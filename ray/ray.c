# include "ray.h"

t_vector3			ray_intersect(const t_ray *me)
{
	t_vector3		tmp;

	tmp = vector3_mul(&me->direction, me->t);
	return (vector3_add(&me->origin, &tmp));
}
