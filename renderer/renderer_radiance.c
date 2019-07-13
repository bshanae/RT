#include "renderer.h"

void					vector3_stupid_mul(t_vector3 *v1, VECTOR3_REF v2)
{
	v1->x *= v2->x;
	v1->y *= v2->y;
	v1->z *= v2->z;
}

static t_vector3		renderer_radiance_path(t_renderer *renderer)
{
	t_vector3			color;

	t_vector3			radiance_emission;
	t_vector3			radiance_light;
	t_vector3			radiance_incident;
	float				incident_cosine;
	t_vector3			radiance_total;



	if (++renderer->depth > PATH_DEPTH)
		return (COLOR_BLACK);

	if (!scene_intersect(renderer->scene, &renderer->intersection))
		return (renderer->depth < 2 ? COLOR_BLACK : COLOR_WHITE);

	color = renderer->intersection.material.color;

	if (renderer->depth > RUSSIAN_DEPTH && fmaxf(fmaxf(color.x, color.y), color.z) < drand48())
		return (COLOR_WHITE);

	radiance_total = (t_vector3){0., 0., 0.};
	radiance_emission = renderer->intersection.material.emission;
	vector3_mul_eq(&radiance_emission, (float)(renderer->depth == 1));

	radiance_light = renderer_radiance_light(renderer);

	renderer->intersection.ray.origin = renderer->intersection.hit;
	renderer->intersection.ray.direction = sampler_uniform(&renderer->intersection.normal, &incident_cosine);

	radiance_incident = vector3_mul_cp(renderer_radiance_path(renderer), incident_cosine);

	radiance_total = vector3_add_ref(&radiance_incident, &radiance_light);

	vector3_stupid_mul(&radiance_total, &color);
	vector3_mul_eq(&radiance_total, 2. * DEFAULT_ALBEDO);

	vector3_add_eq_ref(&radiance_total, &radiance_emission);

	return (radiance_total);
}

void					renderer_radiance(t_renderer *renderer)
{
	t_vector3			radiance_light;
	t_vector3			mask;
	float				incident_cosine;


	renderer->radiance = (t_vector3){0., 0., 0.};
	mask = (t_vector3){1., 1., 1.};

	for (int depth = 0; depth < PATH_DEPTH; ++depth)
	{
		if (!scene_intersect(renderer->scene, &renderer->intersection))
			break ;

		vector3_mul_eq(&mask, DEFAULT_ALBEDO * 2.);

		// RUSSIAN ROULETTE

		if (depth > RUSSIAN_DEPTH && vector3_max(&renderer->intersection.material.color) < drand48())
			break ;

		// EMISSION

		if (!depth)
			vector3_add_eq_ref(&renderer->radiance, &renderer->intersection.material.emission);

		// EXPLICIT LIGHT SAMPLING

		radiance_light = renderer_radiance_light(renderer);
		vector3_stupid_mul(&radiance_light, &renderer->intersection.material.color);
		vector3_stupid_mul(&radiance_light, &mask);
		vector3_add_eq_ref(&renderer->radiance, &radiance_light);

		// NEXT STEP

		renderer->intersection.ray.origin = renderer->intersection.hit;
		renderer->intersection.ray.direction = sampler_uniform(&renderer->intersection.normal, &incident_cosine);

		vector3_stupid_mul(&mask, &renderer->intersection.material.color);
		vector3_mul_eq(&mask, incident_cosine);
	}
}