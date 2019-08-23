#include "gui_signal_x.h"

gboolean			gui_signal_camera_filter_antialiasing
					(GtkWidget *widget, gboolean state, gpointer ptr)
{
	t_gui			*gui;

	gui = (t_gui *)ptr;
	gui->renderer->data.camera->antialiasing = state;
	cl_renderer_flag_set(gui->renderer, cl_flag_update_camera);
	cl_renderer_flag_set(gui->renderer, cl_flag_reset_samples);
	cl_renderer_render(gui->renderer);
	return (FALSE);
}

gboolean			gui_signal_camera_filter_focus
					(GtkWidget *widget, gboolean state, gpointer ptr)
{
	t_gui			*gui;

	gui = (t_gui *)ptr;
	gui->renderer->data.camera->focus = state;
	cl_renderer_flag_set(gui->renderer, cl_flag_update_camera);
	cl_renderer_flag_set(gui->renderer, cl_flag_reset_samples);
	cl_renderer_render(gui->renderer);
	return (FALSE);
}
