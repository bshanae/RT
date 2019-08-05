#include "vector3.h"

double 				vector3_dot_ref(VECTOR3_REF v1, VECTOR3_REF v2)
{
	return (v1->x * v2->x + v1->y * v2->y + v1->z * v2->z);
}

double 				vector3_dot_cp(t_vector3 v1, t_vector3 v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}