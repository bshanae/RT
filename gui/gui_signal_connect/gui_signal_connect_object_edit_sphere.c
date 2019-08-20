#include "gui_signal_connect.h"

void 				gui_signal_connect_object_edit_sphere(t_gui *gui)
{
	GUI_CONNECT(gui->builder, gui_signal_object_edit_sphere_position_x);
	GUI_CONNECT(gui->builder, gui_signal_object_edit_sphere_position_y);
	GUI_CONNECT(gui->builder, gui_signal_object_edit_sphere_position_z);
	GUI_CONNECT(gui->builder, gui_signal_object_edit_sphere_radius);
}