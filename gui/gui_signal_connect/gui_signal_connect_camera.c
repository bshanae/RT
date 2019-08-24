#include "gui_signal_connect.h"

void 				gui_signal_connect_camera(t_gui *gui)
{
	RT_GUI_CONNECT(gui->builder, gui_signal_camera_entry_insert);
	RT_GUI_CONNECT(gui->builder, gui_signal_camera_entry_delete);
	RT_GUI_CONNECT(gui->builder, gui_signal_camera_apply);
	RT_GUI_CONNECT(gui->builder, gui_signal_camera_reset);
	RT_GUI_CONNECT(gui->builder, gui_signal_camera_filter_antialiasing);
	RT_GUI_CONNECT(gui->builder, gui_signal_camera_filter_focus);
}