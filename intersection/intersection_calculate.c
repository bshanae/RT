#include "intersection.h"

t_vector3			intersection_calculate(t_intersection *intersection)
{
	return
	(
		vector3_add_cp
		(
			intersection->origin,
			vector3_mul_ref(&intersection->direction, intersection->t)
		)
	);
}
