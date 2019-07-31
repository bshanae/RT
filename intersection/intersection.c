#include "intersection.h"

void				intersection_reset(t_intersection *me)
{
	me->ray.t = RAY_T_MAX;
	me->diffuse_intensity = 0.;
	me->specular_intensity = 0.;
	me->shadow_ratio = 1.;
	me->stereoscopy_mode = 0;
}

void				intersection_reflect(t_intersection *target, const t_intersection *source)
{
	t_vector3		temp;

	temp = vector3_mul(&source->normal, -2. * vector3_dot(&source->normal, &source->ray.direction));
	vector3_add_eq(&temp, &source->ray.direction);
	vector3_normalize(&temp);
	target->ray.direction = temp;
	target->ray.origin = ray_intersect(&source->ray);
}

void				intersection_refract(t_intersection *target, const t_intersection *source)
{
	t_vector3		refracted;
	t_vector3		a, b;
	t_vector3		m;
	double		sin_alpha;
	double		sin_beta;
	double		cos_beta;

	m = vector3_mul(&source->normal, -1. * vector3_dot(&source->normal, &source->ray.direction));
	vector3_add_eq(&m, &source->ray.direction);
	vector3_normalize(&m);
	sin_alpha = vector3_s_length(vector3_s_cross(vector3_mul(&source->ray.direction, -1.), source->normal));
	sin_beta = sin_alpha / 1.008;
	cos_beta = sqrtf(1 - sin_beta * sin_beta);
	a = vector3_mul(&source->normal, -1 * cos_beta);
	b = vector3_mul(&m, sin_beta);
	refracted = vector3_add(&a, &b);
	vector3_normalize(&refracted);
	target->ray.direction = refracted;
	target->ray.origin = ray_intersect(&source->ray);
}

t_vector3           intersection_light_direction(t_intersection *intersection, t_light *light)
{
	t_vector3       temp[2];

	if (light->type == light_directional)
		temp[0] = light->vector;
	else if (light->type == light_point)
	{
		temp[1] = ray_intersect(&intersection->ray);
		temp[0] = vector3_sub(&light->vector, temp + 1);
	}
	return (temp[0]);
}

void                intersection_lighting_diffuse(t_intersection *intersection, t_light *light, t_vector3 *light_direction)
{
	double		dot;

	if ((dot = vector3_dot(light_direction, &intersection->normal)) > 0.)
		intersection->diffuse_intensity += intersection->shadow_ratio * intersection->material->diffuse * light->intensity * dot / vector3_length(light_direction);
}


void                intersection_lighting_specular(t_intersection *intersection, t_light *light, t_vector3 *light_direction)
{
	t_vector3       halfway;
	double		dot;

	halfway = vector3_sub(light_direction, &intersection->ray.direction);
	vector3_normalize(&halfway);
	if ((dot = vector3_dot(&halfway, &intersection->normal)) > 0.)
		intersection->specular_intensity += intersection->shadow_ratio * intersection->material->specular * light->intensity * pow(dot, BLINN_ALPHA);

}

void                intersection_make_color(t_intersection *intersection)
{
	t_vector3		white;

	white = (t_vector3){1., 1., 1.};
	intersection->color = vector3_mul(&intersection->material->color, intersection->diffuse_intensity);
	vector3_mul_eq(&white, intersection->specular_intensity);
	vector3_add_eq(&intersection->color, &white);
}