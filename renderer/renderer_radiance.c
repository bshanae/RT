#include "renderer.h"

void					vector3_stupid_mul_eq(t_vector3 *v1, VECTOR3_REF v2)
{
	v1->x *= v2->x;
	v1->y *= v2->y;
	v1->z *= v2->z;
}

t_vector3				vector3_stupid_mul_cp(const t_vector3 v1, const t_vector3 v2)
{
	return ((t_vector3)
	{
		v1.x * v2.x,
		v1.y * v2.y,
		v1.z * v2.z
	});
}

void					renderer_radiance(t_renderer *renderer)
{
	t_vector3			radiance_light;
	t_vector3			mask;
	float				incident_cosine;
	float 				choice;


	renderer->radiance = (t_vector3){0., 0., 0.};
	mask = (t_vector3){1., 1., 1.};

	for (int depth = 0; depth < PATH_DEPTH; ++depth)
	{
		if (!scene_intersect(renderer->scene, &renderer->intersection))
			break ;

//		vector3_mul_eq(&mask, 2. * DEFAULT_ALBEDO);

		// RUSSIAN ROULETTE

		if (depth > RUSSIAN_DEPTH && vector3_max(&renderer->intersection.material.color) < drand48())
			break ;

		if (renderer->intersection.material.reflection || renderer->intersection.material.refraction)
		{
			choice = drand48();
			if (choice < renderer->intersection.material.reflection) // reflection
				intersection_reflect(&renderer->intersection, &renderer->intersection);
			else // refraction
				intersection_refract(&renderer->intersection, &renderer->intersection);
			vector3_div_eq(&mask, choice < renderer->intersection.material.reflection ? 1. : renderer->intersection.material.refraction);
		}
		else
		{
			// EMISSION

			vector3_add_eq_cp(&renderer->radiance, vector3_stupid_mul_cp(mask, renderer->intersection.material.emission));

			// EXPLICIT LIGHT SAMPLING

			radiance_light = renderer_radiance_light(renderer);
			vector3_stupid_mul_eq(&radiance_light, &renderer->intersection.material.color);
			vector3_stupid_mul_eq(&radiance_light, &mask);
			vector3_add_eq_ref(&renderer->radiance, &radiance_light);

			// NEXT STEP

			renderer->intersection.ray.origin = renderer->intersection.hit;
			renderer->intersection.ray.direction = sampler_uniform(&renderer->intersection.normal, &incident_cosine);
			vector3_stupid_mul_eq(&mask, &renderer->intersection.material.color);

#ifdef SAMPLING_UNIFORM
			vector3_mul_eq(&mask, incident_cosine);
#endif

#ifdef SAMPLING_COSINE_OTTE
			vector3_mul_eq(&mask, incident_cosine);
#endif

#ifdef SAMPLING_COSINE_PBRT

#endif
		}
	}
}