#include "gui_color.h"

RT_F4_API			gui_color_to_f4(const t_gui_color *source)
{
	RT_F4_API		result;

	result.x = source->red;
	result.y = source->green;
	result.z = source->blue;
	result.w = source->alpha;
	return (result);
}
