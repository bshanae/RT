#include "gui_scene_common.h"

void				gui_scene_common_connect(t_gui_scene_common *common, ...)
{
	va_list			args;

	va_start(args, common);
	common->ptr_scene = va_arg(args, t_scene *);
	common->ptr_light = va_arg(args, t_rt_light_mod *);
	va_end(args);
	common->connected = rt_true;
}

