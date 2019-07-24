#include "intersection.h"

void				intersection_refract(t_intersection *destination, const t_intersection *source)
{
	t_vector3		refracted;
	t_vector3		a, b;
	t_vector3		m;
	float			sin_alpha;
	float			sin_beta;
	float			cos_beta;

	m = vector3_mul_ref(&source->normal, -1. * vector3_dot_ref(&source->normal, &source->ray.direction));
	vector3_add_eq_ref(&m, &source->ray.direction);
	vector3_normalize(&m);
	sin_alpha = vector3_length_cp(vector3_cross_cp(vector3_mul_ref(&source->ray.direction, -1.), source->normal));
	sin_beta = sin_alpha / 1.02;
	cos_beta = sqrtf(1 - sin_beta * sin_beta);
	a = vector3_mul_ref(&source->normal, -1 * cos_beta);
	b = vector3_mul_ref(&m, sin_beta);
	refracted = vector3_add_ref(&a, &b);
	vector3_normalize(&refracted);
	destination->ray.direction = refracted;
	destination->ray.origin = source->hit;
}

