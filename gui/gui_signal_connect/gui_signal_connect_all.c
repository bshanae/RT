#include "gui_signal_connect.h"

void 				gui_signal_connect_all(t_gui *gui)
{
	GUI_CONNECT(gui->builder, gui_signal_exit)
	GUI_CONNECT(gui->builder, gui_signal_key)
	gui_signal_connect_scene_edit(gui);
	gui_signal_connect_scene_add(gui);
	gtk_builder_connect_signals(gui->builder, (gpointer)gui);
}