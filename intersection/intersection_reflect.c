#include "intersection.h"

void				intersection_reflect(t_intersection *destination, const t_intersection *source)
{
	t_vector3		reflected;

	reflected = vector3_mul_ref(&source->normal, -2. * vector3_dot_ref(&source->normal, &source->ray.direction));
	vector3_add_eq_ref(&reflected, &source->ray.direction);
	vector3_normalize(&reflected);
	destination->ray.direction = reflected;
	destination->ray.origin = source->hit;
}

