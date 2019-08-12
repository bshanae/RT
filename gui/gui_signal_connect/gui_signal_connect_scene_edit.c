#include "gui_signal_connect.h"

void				gui_signal_connect_scene_edit(t_gui *gui)
{
	GUI_CONNECT(gui->builder, gui_signal_scene_edit_select)
	GUI_CONNECT(gui->builder, gui_signal_scene_edit_add)
	GUI_CONNECT(gui->builder, gui_signal_scene_edit_remove)
	gui_signal_connect_object_edit_sphere(gui);
	gui_signal_connect_object_edit_plane(gui);
}

