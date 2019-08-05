#include "vector3.h"

double 				vector3_max(VECTOR3_REF v)
{
	return (fmaxf(fmaxf(v->x, v->y), v->z));
}