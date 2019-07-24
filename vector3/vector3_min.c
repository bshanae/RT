#include "vector3.h"

float 				vector3_min_component(VECTOR3_REF v)
{
	return (fminf(fminf(v->x, v->y), v->z));
}

t_vector3 			vector3_min_vector(VECTOR3_REF v1, VECTOR3_REF v2)
{
	return ((t_vector3)
	{
		fminf(v1->x, v2->x),
		fminf(v1->y, v2->y),
		fminf(v1->z, v2->z)
	});
}