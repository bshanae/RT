#include "gui_signal_x.h"

gboolean			gui_signal_camera_focus_enable
					(GtkWidget *widget, gboolean state, gpointer ptr)
{
	t_gui			*gui;

	gui = (t_gui *)ptr;
	gui->renderer->data.camera->focus = state;
	gtk_widget_set_sensitive(GTK_WIDGET(gui->camera->focus_box), state);
	cl_renderer_flag_set(gui->renderer, cl_flag_update_camera);
	cl_renderer_flag_set(gui->renderer, cl_flag_reset_samples);
	cl_renderer_render(gui->renderer);
	return (FALSE);
}

void				gui_signal_camera_focus_auto
					(GtkWidget *widget, gpointer ptr)
{
	t_gui			*gui;

	gui = (t_gui *)ptr;
	gui->camera->focus_request = 1;
	gtk_widget_set_sensitive(GTK_WIDGET(gui->notebook), 0);
}