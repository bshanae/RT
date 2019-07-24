#include "vector3.h"

t_vector3			vector3_cross_ref(VECTOR3_REF v1, VECTOR3_REF v2)
{
	return ((t_vector3)
	{
		.x = v1->y * v2->z - v1->z * v2->y,
		.y = v1->z * v2->x - v1->x * v2->z,
		.z = v1->x * v2->y - v1->y * v2->x
	});
}

t_vector3			vector3_cross_cp(t_vector3 v1, t_vector3 v2)
{
	return ((t_vector3)
	{
		.x = v1.y * v2.z - v1.z * v2.y,
		.y = v1.z * v2.x - v1.x * v2.z,
		.z = v1.x * v2.y - v1.y * v2.x
	});
}
