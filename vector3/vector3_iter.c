#include "vector3.h"

float				*vector3_iter(const t_vector3 *me, int i)
{
	if (i < 0 || i > 3)
		return (NULL);
	return ((float *)&me->x + i);
}