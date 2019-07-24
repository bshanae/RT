#include "ray.h"

t_vector3			ray_calculate(const t_ray *ray)
{
	return
	(
		vector3_add_cp
		(
			ray->origin,
			vector3_mul_ref(&ray->direction, ray->t)
		)
	);
}