#include "intersection.h"

void				intersection_reset(t_intersection *me)
{
	me->ray.t = RAY_T_MAX;
	me->diffuse_intensity = 0.;
	me->specular_intensity = 0.;
	me->shadow_ratio = 1.;
}

t_vector3           intersection_light_direction(t_intersection *intersection, t_light *light)
{
	t_vector3       temp[2];

	temp[1] = ray_intersect(&intersection->ray);
	temp[0] = vector3_sub(&light->position, temp + 1);
	return (vector3_normalized(temp + 0));
}

void                intersection_lighting_diffuse(t_intersection *intersection, t_light *light, t_vector3 *light_direction)
{
	float			dot;

	if ((dot = vector3_dot(light_direction, &intersection->normal)) > 0.)
		intersection->diffuse_intensity += intersection->shadow_ratio * light->intensity * dot;
}


void                intersection_lighting_specular(t_intersection *intersection, t_light *light, t_vector3 *light_direction)
{
	t_vector3       halfway;
	float		dot;

	halfway = vector3_sub(light_direction, &intersection->ray.direction);
	vector3_normalize(&halfway);
	if ((dot = vector3_dot(&halfway, &intersection->normal)) > 0.)
		intersection->specular_intensity += intersection->shadow_ratio * intersection->material.specular * light->intensity * pow(dot, 60.);

}

void                intersection_make_color(t_intersection *intersection)
{
	t_vector3		white;

	white = (t_vector3){1., 1., 1.};
	intersection->color = vector3_mul(&intersection->material.color, intersection->diffuse_intensity);
	vector3_mul_eq(&white, intersection->specular_intensity);
	vector3_add_eq(&intersection->color, &white);
}
