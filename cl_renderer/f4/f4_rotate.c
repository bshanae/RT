#include "f4.h"

static void			f4_rotate_x(RT_F4_API *v, float theta)
{
	RT_F4_API		copy;

	copy = *v;
	v->y = copy.y * RT_COS_API(theta) + copy.z * RT_SIN_API(theta);
	v->z = -1 * copy.y * RT_SIN_API(theta) + copy.z * RT_COS_API(theta);
}

static void			f4_rotate_y(RT_F4_API *v, float theta)
{
	RT_F4_API		copy;

	copy = *v;
	v->x = copy.x * RT_COS_API(theta) + copy.z * RT_SIN_API(theta);
	v->z = -1 * copy.x * RT_SIN_API(theta) + copy.z * RT_COS_API(theta);
}

RT_F4_API 			f4_rotate(
					RT_F4_API v,
					t_f4_rotation_axis axis,
					t_f4_rotation_direction direction,
					RT_F theta)
{
	if (direction == rt_rotation_negative)
		theta *= -1;
	if (axis == rt_rotation_x)
		f4_rotate_x(&v, theta);
	else if (axis == rt_rotation_y)
		f4_rotate_y(&v, theta);
	return (v);
}