#include "renderer.h"

#define IS_BLACK(v)		(!(v)->x && !(v)->y && !(v)->z)

void					renderer_radiance(t_renderer *renderer)
{
	t_vector3			radiance_light;
	t_vector3			mask;
	float 				cosine;
	float 				choice;


	renderer->radiance = (t_vector3){0., 0., 0.};
	mask = (t_vector3){1., 1., 1.};

	for (int depth = 0; depth < PATH_DEPTH; ++depth)
	{
		if (!scene_intersect(renderer->scene, &renderer->intersection))
		{
//			vector3_add_eq_cp(&renderer->radiance, vector3_component_mul_cp(BACKGROUND, mask));
			break ;
		}

		if (double_intersection)
			renderer->radiance = (t_vector3){0., 0., 1.};

		// RUSSIAN ROULETTE

		if (depth > RUSSIAN_DEPTH && vector3_max_component(&renderer->intersection.material.color) < drand48())
			break ;

		if (renderer->intersection.material.reflection || renderer->intersection.material.refraction)
		{
			choice = drand48();
			// REFLECTION
			if (choice < renderer->intersection.material.reflection)
				intersection_reflect(&renderer->intersection, &renderer->intersection);
			else // REFRACTION
				intersection_refract(&renderer->intersection, &renderer->intersection);
			vector3_div_eq(&mask, choice < renderer->intersection.material.reflection ? 1. : renderer->intersection.material.refraction);
		}
		else
		{
			// EMISSION

			vector3_add_eq_cp(&renderer->radiance, vector3_component_mul_cp(mask, renderer->intersection.material.emission));

			// EXPLICIT LIGHT SAMPLING

			if (LIGHT_SAMPLING)
			{
				radiance_light = renderer_radiance_light(renderer);
				vector3_component_mul_eq_ref(&radiance_light, &renderer->intersection.material.color);
				vector3_component_mul_eq_ref(&radiance_light, &mask);
				vector3_add_eq_ref(&renderer->radiance, &radiance_light);
			}

			// NEXT STEP

			renderer->intersection.ray.origin = renderer->intersection.hit;
			renderer->intersection.ray.direction = sampler_uniform(&renderer->intersection.normal, &cosine);

			vector3_component_mul_eq_ref(&mask, &renderer->intersection.material.color);
			vector3_mul_eq(&mask, cosine);
		}
	}
	if (SRGB)
		color_correct(&renderer->radiance);
}