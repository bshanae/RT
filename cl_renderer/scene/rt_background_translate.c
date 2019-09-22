#include "scene.h"

CHAR_REF			rt_background_translate(t_rt_background i)
{
	if (i == rt_background_none)
		return ("None");
	else if (i == rt_background_one)
		return ("One color");
	else if (i == rt_background_interpolation)
		return ("Interpolated color");
	rt_raise_warning("rt_background : unknown value");
}