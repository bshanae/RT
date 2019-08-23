#include "gui_signal_x.h"

void 				gui_signal_settings_tracing_rt
					(GtkWidget *widget, gpointer ptr)
{
	t_gui			*gui;

	gui = (t_gui *)ptr;
	g_signal_handlers_block_by_func(G_OBJECT(gui->settings->tracing_rm),
		gui_signal_settings_tracing_rm, ptr);
	gtk_toggle_button_set_active(gui->settings->tracing_rm, 0);
	g_signal_handlers_unblock_by_func(G_OBJECT(gui->settings->tracing_rm),
		gui_signal_settings_tracing_rm, ptr);
	gui->renderer->data.settings.rm_mod = 0;
	gtk_stack_set_visible_child_name(gui->settings->stack, "rt");
}

void 				gui_signal_settings_tracing_rm
					(GtkWidget *widget, gpointer ptr)
{
	t_gui			*gui;

	gui = (t_gui *)ptr;
	g_signal_handlers_block_by_func(G_OBJECT(gui->settings->tracing_rt),
		gui_signal_settings_tracing_rt, ptr);
	gtk_toggle_button_set_active(gui->settings->tracing_rt, 0);
	g_signal_handlers_unblock_by_func(G_OBJECT(gui->settings->tracing_rt),
		gui_signal_settings_tracing_rt, ptr);
	gui->renderer->data.settings.rm_mod = 1;
	gtk_stack_set_visible_child_name(gui->settings->stack, "rm");
}


