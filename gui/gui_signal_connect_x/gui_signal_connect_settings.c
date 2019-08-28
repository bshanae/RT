#include "gui_signal_connect_x.h"

void				gui_signal_connect_settings(t_gui *gui)
{
	RT_GUI_CONNECT(gui, gui_signal_settings_entry_changed);
	RT_GUI_CONNECT(gui, gui_signal_settings_entry_insert);
	RT_GUI_CONNECT(gui, gui_signal_settings_entry_delete);
	RT_GUI_CONNECT(gui, gui_signal_settings_reset);
	RT_GUI_CONNECT(gui, gui_signal_settings_apply);
	RT_GUI_CONNECT(gui, gui_signal_settings_tracing_rt);
	RT_GUI_CONNECT(gui, gui_signal_settings_tracing_rm);
	RT_GUI_CONNECT(gui, gui_signal_settings_light);
}