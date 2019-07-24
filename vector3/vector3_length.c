#include "vector3.h"

float 					vector3_length_ref(VECTOR3_REF v)
{
	return (sqrtf(v->x * v->x + v->y * v->y + v->z * v->z));
}

float 					vector3_length_cp(t_vector3 v)
{
	return (sqrtf(v.x * v.x + v.y * v.y + v.z * v.z));
}
