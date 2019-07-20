#include "vector3.h"

float 				vector3_min(VECTOR3_REF v)
{
	return (fminf(fminf(v->x, v->y), v->z));
}