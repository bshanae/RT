#include "gui_signal_connect_x.h"

void 				gui_signal_connect_camera(t_gui *gui)
{
	RT_GUI_CONNECT(gui, gui_signal_camera_entry_insert);
	RT_GUI_CONNECT(gui, gui_signal_camera_entry_delete);
	RT_GUI_CONNECT(gui, gui_signal_camera_filter_antialiasing);
	RT_GUI_CONNECT(gui, gui_signal_camera_filter_focus);
	RT_GUI_CONNECT(gui, gui_signal_camera_screen_save);
	RT_GUI_CONNECT(gui, gui_signal_camera_screen_success_close);
	RT_GUI_CONNECT(gui, gui_signal_camera_screen_fail_close);
	RT_GUI_CONNECT(gui, gui_signal_camera_apply);
	RT_GUI_CONNECT(gui, gui_signal_camera_reset);
}