#include "vector3.h"

double 					vector3_length_ref(VECTOR3_REF v)
{
	return (sqrt(v->x * v->x + v->y * v->y + v->z * v->z));
}

double 					vector3_length_cp(t_vector3 v)
{
	return (sqrt(v.x * v.x + v.y * v.y + v.z * v.z));
}
