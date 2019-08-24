#include "gui_color.h"

t_gui_color			gui_color_from_f4(const RT_F4_API *source)
{
	t_gui_color		color;

	color.red = source->x;
	color.green = source->y;
	color.blue = source->z;
	color.alpha = source->w;
	return (color);
}