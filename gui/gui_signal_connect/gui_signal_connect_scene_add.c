#include "gui_signal_connect.h"

void				gui_signal_connect_scene_add(t_gui *gui)
{
	GUI_CONNECT(gui->builder, gui_signal_scene_add_cancel)
	GUI_CONNECT(gui->builder, gui_signal_scene_add_response_yes)
	GUI_CONNECT(gui->builder, gui_signal_scene_add_response_no)
	GUI_CONNECT(gui->builder, gui_signal_scene_add_type_auto);
	GUI_CONNECT(gui->builder, gui_signal_scene_add_type_manual);
}