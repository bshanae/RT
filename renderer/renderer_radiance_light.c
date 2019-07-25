#include "renderer.h"

#define IS_BLACK(v)		(!(v)->x && !(v)->y && !(v)->z)

t_vector3				renderer_radiance_light(t_renderer *renderer)
{
	t_intersection		intersection;
	t_vector3			radiance;
	t_vector3			light_position;
	t_vector3			light_direction;
	float				emission_intensity;
	float 				cos_a_max;
	float 				omega;
	float 				sphere_radius;

	radiance = (t_vector3){0., 0., 0.};
	for (int i = 0; i < renderer->scene->shapes_length; ++i)
	{
		if (i == renderer->intersection.shape_index)
			continue ;
		if (IS_BLACK(&renderer->scene->shapes[i].material.emission) || renderer->scene->shapes[i].id != SHAPE_ID_SPHERE)
			continue ;

		light_position = shape_random_sphere(renderer->scene->shapes + i);
		light_direction = vector3_sub_ref(&light_position, &renderer->intersection.hit);
		vector3_normalize(&light_direction);

		intersection.ray.origin = renderer->intersection.hit;
		intersection.ray.direction = light_direction;

		if (!scene_intersect(renderer->scene, &intersection))
			continue;
		if (intersection.shape_index != i)
			continue;
		emission_intensity = vector3_dot_ref(&renderer->intersection.normal, &intersection.ray.direction);
		if (emission_intensity < 0.)
			continue ;

		sphere_radius = ((t_shape_data_sphere *)renderer->scene->shapes->data)->radius;
		cos_a_max = sqrtf(1. - sphere_radius * sphere_radius / vector3_length_cp(vector3_sub_ref(&renderer->intersection.hit, &light_position)));
		omega = 2 * M_PI * (1 - cos_a_max);
		vector3_add_eq_cp(&radiance, vector3_mul_ref(&renderer->scene->shapes[i].material.emission, emission_intensity * omega * M_1_PI));
	}
	return (radiance);
}