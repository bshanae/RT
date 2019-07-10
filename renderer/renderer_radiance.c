#include "renderer.h"

static void				create_coordiante_system(const t_vector3 *normal, t_vector3 *nt, t_vector3 *nb)
{
	if (fabsf(normal->x) > fabsf(normal->y))
		*nt = (t_vector3){normal->z, 0., -1.f * normal->x};
	else
		*nt = (t_vector3){0., -1.f * normal->z, normal->y};
	vector3_normalize(nt);
	*nb = vector3_cross_ref(normal, nt);
}

static t_vector3		generate_sample(const float *r1, const float *r2)
{
	float 				sin_theta;
	float 				phi;

	phi = 2.f * M_PI * *r2;
	sin_theta = sqrtf(1.f - *r1 * *r1);

	return ((t_vector3)
	{
			sin_theta * cosf(phi),
			*r1,
			sin_theta * sinf(phi)
	});
}

static t_vector3		convert_sample(const t_vector3 *normal, const t_vector3 *sample, const t_vector3 *nt, const t_vector3 *nb)
{
	return ((t_vector3)
	{
			sample->x * nb->x + sample->y * normal->x + sample->z * nt->x,
			sample->x * nb->y + sample->y * normal->y + sample->z * nt->y,
			sample->x * nb->z + sample->y * normal->z + sample->z * nt->z,
	});
}

#define IS_BLACK(v)		(!(v)->x && !(v)->y && !(v)->z)

void					vector3_stupid_mul(t_vector3 *v1, VECTOR3_REF v2)
{
	v1->x *= v2->x;
	v1->y *= v2->y;
	v1->z *= v2->z;
}

static t_vector3		renderer_radiance_path(t_renderer *renderer)
{
	t_vector3			color;
	int 				shape_id;

	t_vector3			radiance_emission;
	t_vector3			radiance_light;
	t_vector3			radiance_incident;
	t_vector3			radiance_total;

	t_vector3			light_position;
	t_vector3			light_direction;
	float				emission_intensity;
	t_shape_data_sphere	*sphere_data;
	t_vector3			vector_to_sphere;
	float 				vector_to_sphere_length;
	float 				cos_a_max;
	float 				omega;
	t_vector3			nt;
	t_vector3			nb;
	float 				r[2];

	t_vector3			sample_direction;

	if (++renderer->depth > PATH_DEPTH)
		return (COLOR_BLACK);
	renderer->intersection_shape.t = INTERSECTION_MAX;
	if ((shape_id = scene_intersect(renderer->scene, &renderer->intersection_shape)) == -1)
		return (renderer->depth < 2 ? COLOR_BLACK : COLOR_WHITE);

	color = renderer->intersection_shape.material.color;

	radiance_total = (t_vector3){0., 0., 0.};
	radiance_emission = renderer->intersection_shape.material.emission;
	vector3_mul_eq(&radiance_emission, (float)(renderer->depth == 1));
	radiance_light = (t_vector3){0., 0., 0.};

	for (int i = 0; i < renderer->scene->shapes_length; i++)
	{
		if (i == shape_id)
			continue ;
		if (IS_BLACK(&renderer->scene->shapes[i].material.emission) || renderer->scene->shapes[i].id != SHAPE_ID_SPHERE)
			continue ;
		light_position = shape_random_sphere(renderer->scene->shapes + i);
		light_direction = vector3_sub_ref(&light_position, &renderer->intersection_shape.hit);
		vector3_normalize(&light_direction);
		renderer->intersection_light.origin = renderer->intersection_shape.hit;
		renderer->intersection_light.direction = light_direction;
		renderer->intersection_light.t = INTERSECTION_MAX;
		if (scene_intersect(renderer->scene, &renderer->intersection_light) != i)
			continue ;
		emission_intensity = vector3_dot_ref(&renderer->intersection_shape.normal, &renderer->intersection_light.direction);
		if (emission_intensity < 0.)
			continue ;
//		sphere_data = (t_shape_data_sphere *)renderer->scene->shapes->data;
//		vector_to_sphere = vector3_sub_ref(&sphere_data->center, &renderer->intersection_light.origin);
//		vector_to_sphere_length = vector3_length_ref(&vector_to_sphere);
//		cos_a_max = vector_to_sphere_length / sqrtf(sphere_data->radius * sphere_data->radius + vector_to_sphere_length * vector_to_sphere_length);
//		omega = 2 * M_PI * (1.f - cos_a_max);
//		printf("%f\n", cos_a_max);
		vector3_add_eq_cp(&radiance_light, vector3_mul_ref(&renderer->scene->shapes[i].material.emission, emission_intensity));
	}
	
	create_coordiante_system(&renderer->intersection_shape.normal, &nt, &nb);
	r[0] = drand48();
	r[1] = drand48();
	sample_direction = generate_sample(r, r + 1);
	sample_direction = convert_sample(&renderer->intersection_shape.normal, &sample_direction, &nt, &nb);

	renderer->intersection_shape.origin = renderer->intersection_shape.hit;
	renderer->intersection_shape.direction = sample_direction;
	radiance_incident = renderer_radiance_path(renderer);

	vector3_stupid_mul(&radiance_light, &color);
	vector3_stupid_mul(&radiance_incident, &color);

	vector3_add_eq_ref(&radiance_total, &radiance_emission);
	vector3_add_eq_ref(&radiance_total, &radiance_light);
	vector3_add_eq_ref(&radiance_total, &radiance_incident);

	return (radiance_total);
}

void				renderer_get_radiance(t_renderer *renderer)
{
	renderer->depth = 0;
	renderer->radiance = renderer_radiance_path(renderer);
}