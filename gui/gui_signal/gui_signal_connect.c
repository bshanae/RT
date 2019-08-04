#include "gui_signal.h"

void				gui_signal_connect(t_gui *gui)
{
	gtk_builder_add_callback_symbol(gui->builder, "gui_signal_selected", G_CALLBACK(gui_signal_selected));
	gtk_builder_add_callback_symbol(gui->builder, "gui_signal_sphere_pos_x", G_CALLBACK(gui_signal_sphere_pos_x));
	gtk_builder_connect_signals(gui->builder, (gpointer)gui);
}