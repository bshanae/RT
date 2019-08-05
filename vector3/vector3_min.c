#include "vector3.h"

double 				vector3_min(VECTOR3_REF v)
{
	return (fmin(fmin(v->x, v->y), v->z));
}