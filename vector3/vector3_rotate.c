#include "vector3.h"

void				vector3_rotate_x(t_vector3 *me, float theta)
{
	t_vector3		    	copy;

	copy = *me;
	me->y = copy.y * cosf(theta) + copy.z * sinf(theta);
	me->z = -1 * copy.y * sinf(theta) + copy.z * cosf(theta);
}

void				vector3_rotate_y(t_vector3 *me, float theta)
{
	t_vector3		    	copy;

	copy = *me;
	me->x = copy.x * cosf(theta) + copy.z * sinf(theta);
	me->z = -1 * copy.x * sinf(theta) + copy.z * cosf(theta);
}