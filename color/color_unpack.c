#include "color.h"

int					color_unpack(t_vector3 v)
{
	t_color			c;

	c.rgb.r = fabsf(v.x) > 1. ? 255 : (char)(255 * v.x);
	c.rgb.g = fabsf(v.y) > 1. ? 255 : (char)(255 * v.y);
	c.rgb.b = fabsf(v.z) > 1. ? 255 : (char)(255 * v.z);
	return (c.mix);
}