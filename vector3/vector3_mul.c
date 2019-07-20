#include "vector3.h"

t_vector3				vector3_mul_ref(VECTOR3_REF v, float f)
{
	return ((t_vector3)
	{
		.x = v->x * f,
		.y = v->y * f,
		.z = v->z * f
	});
}

t_vector3				vector3_mul_cp(t_vector3 v, float f)
{
	return ((t_vector3)
	{
		.x = v.x * f,
		.y = v.y * f,
		.z = v.z * f
	});
}

void					vector3_mul_eq(t_vector3 *v, float f)
{
	v->x *= f;
	v->y *= f;
	v->z *= f;
}