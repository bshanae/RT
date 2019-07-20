#include "intersection.h"

void					intersection_reflect(t_intersection *destination, const t_intersection *source)
{
	t_vector3		temp;

	temp = vector3_mul_ref(&source->normal, -2. * vector3_dot_ref(&source->normal, &source->ray.direction));
	vector3_add_eq_ref(&temp, &source->ray.direction);
	vector3_normalize(&temp);
	destination->ray.direction = temp;
	destination->ray.origin = source->hit;
}

