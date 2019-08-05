#include "vector3.h"

t_vector3				vector3_component_mul_ref(VECTOR3_REF v1, VECTOR3_REF v2)
{
	return ((t_vector3)
	{
		.x = v1->x * v2->x,
		.y = v1->y * v2->y,
		.z = v1->z * v2->z
	});
}

t_vector3				vector3_component_mul_cp(t_vector3 v1, t_vector3 v2)
{
	return ((t_vector3)
	{
		.x = v1.x * v2.x,
		.y = v1.y * v2.y,
		.z = v1.z * v2.z
	});
}

void					vector3_component_mul_eq_ref(t_vector3 *v1, VECTOR3_REF v2)
{
	v1->x *= v2->x;
	v1->y *= v2->y;
	v1->z *= v2->z;
}

void					vector3_component_mul_eq_cp(t_vector3 *v1, t_vector3 v2)
{
	v1->x *= v2.x;
	v1->y *= v2.y;
	v1->z *= v2.z;
}