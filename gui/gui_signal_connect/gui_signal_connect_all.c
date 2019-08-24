#include "gui_signal_connect.h"

void				test(GtkWidget *widget, gpointer ptr)
{
	printf("hi\n");
}

void 				gui_signal_connect_all(t_gui *gui)
{
	RT_GUI_CONNECT(gui->builder, test);

	RT_GUI_CONNECT(gui->builder, gui_signal_exit);
	RT_GUI_CONNECT(gui->builder, gui_signal_key);
	gui_signal_connect_camera(gui);
	gui_signal_connect_scene_edit(gui);
	gui_signal_connect_scene_add(gui);
	gui_signal_connect_settings(gui);
	gui_signal_connect_image(gui);
	gtk_builder_connect_signals(gui->builder, (gpointer)gui);
}