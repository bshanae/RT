#include "gui_signal_connect_x.h"

void				gui_signal_connect_settings(t_gui *gui)
{
	printf("GUI Signal: Connecting settings callbacks\n");
	RT_GUI_CONNECT(gui, gui_signal_settings_reset);
	RT_GUI_CONNECT(gui, gui_signal_settings_apply);
	RT_GUI_CONNECT(gui, gui_signal_settings_resize);
	RT_GUI_CONNECT(gui, gui_signal_settings_tracing_rt);
	RT_GUI_CONNECT(gui, gui_signal_settings_tracing_rm);
	RT_GUI_CONNECT(gui, gui_signal_settings_light);
	RT_GUI_CONNECT(gui, gui_signal_settings_illumination_state);
	RT_GUI_CONNECT(gui, gui_signal_settings_motion_blur);
}