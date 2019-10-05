#include "gui_scene_common.h"

void 				gui_scene_common_update_wrap
	(t_gui_scene_common *gui, t_gui_scene_update_function *func)
{
	gui->update_process = rt_true;
	func(gui);
	gui->update_process = rt_false;
}