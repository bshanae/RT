#include "gui_signal_x.h"

gboolean			gui_signal_camera_filter_antialiasing
					(GtkWidget *widget, gboolean state, gpointer ptr)
{
	t_gui			*gui;

	gui = (t_gui *)ptr;
	gui->renderer->data_host.camera->antialiasing = state;
	gui->renderer->flags.update_camera = 1;
	cl_renderer_reset_samples(gui->renderer);
	cl_renderer_render(gui->renderer);
	return (FALSE);
}

gboolean			gui_signal_camera_filter_focus
					(GtkWidget *widget, gboolean state, gpointer ptr)
{
	t_gui			*gui;

	gui = (t_gui *)ptr;
	gui->renderer->data_host.camera->focus = state;
	gui->renderer->flags.update_camera = 1;
	cl_renderer_reset_samples(gui->renderer);
	cl_renderer_render(gui->renderer);
	return (FALSE);
}

void 				gui_signal_camera_filter_focal_length
					(GtkWidget *widget, gpointer ptr)
{
	t_gui			*gui;

	gui = (t_gui *)ptr;
	gui->renderer->data_host.camera->focal_length =
		(RT_F)strtod(gtk_entry_get_text(gui->camera->focal_length), NULL);
	gui->renderer->flags.update_camera = 1;
	cl_renderer_reset_samples(gui->renderer);
	cl_renderer_render(gui->renderer);
}

void 				gui_signal_camera_filter_aperture_size
					(GtkWidget *widget, gpointer ptr)
{
	t_gui			*gui;

	gui = (t_gui *)ptr;
	gui->renderer->data_host.camera->aperture_size =
		(RT_F)strtod(gtk_entry_get_text(gui->camera->aperture_size), NULL);
	gui->renderer->flags.update_camera = 1;
	cl_renderer_reset_samples(gui->renderer);
	cl_renderer_render(gui->renderer);
}