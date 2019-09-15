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
	gtk_stack_set_visible_child_name(gui->settings->stack, "rt");
	cl_renderer_change_tracing_mod(gui->renderer, rt_tracing_mod_rt);
	gui_scene_common_update_all(gui->scene->common, gui->renderer->data.scene);
	gui_queue_push(gui->queue);
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
	gtk_stack_set_visible_child_name(gui->settings->stack, "rm");
	cl_renderer_change_tracing_mod(gui->renderer, rt_tracing_mod_rm);
	gui_scene_common_update_all(gui->scene->common, gui->renderer->data.scene);
	gui_queue_push(gui->queue);
}


