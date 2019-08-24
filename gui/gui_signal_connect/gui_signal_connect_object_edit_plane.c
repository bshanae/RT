#include "gui_signal_connect.h"

void 				gui_signal_connect_object_edit_plane(t_gui *gui)
{
	GUI_CONNECT(gui->builder, gui_signal_object_edit_plane_position_x);
	GUI_CONNECT(gui->builder, gui_signal_object_edit_plane_position_y);
	GUI_CONNECT(gui->builder, gui_signal_object_edit_plane_position_z);
	GUI_CONNECT(gui->builder, gui_signal_object_edit_plane_normal_x);
	GUI_CONNECT(gui->builder, gui_signal_object_edit_plane_normal_y);
	GUI_CONNECT(gui->builder, gui_signal_object_edit_plane_normal_z);
}