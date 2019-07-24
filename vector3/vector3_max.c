#include "vector3.h"

float 				vector3_max_component(VECTOR3_REF v)
{
	return (fmaxf(fmaxf(v->x, v->y), v->z));
}

t_vector3 			vector3_max_vector(VECTOR3_REF v1, VECTOR3_REF v2)
{
	return ((t_vector3)
	{
		fmaxf(v1->x, v2->x),
		fmaxf(v1->y, v2->y),
		fmaxf(v1->z, v2->z)
	});
}