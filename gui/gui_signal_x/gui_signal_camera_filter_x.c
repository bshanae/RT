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

void 				gui_signal_camera_filter_focal_length
					(GtkWidget *widget, gpointer ptr)
{
	t_gui			*gui;

	gui = (t_gui *)ptr;
	gui->renderer->data.camera->focal_length =
		(RT_F)strtod(gtk_entry_get_text(gui->camera->focal_length), NULL);
	cl_renderer_flag_set(gui->renderer, cl_flag_update_camera);
	cl_renderer_flag_set(gui->renderer, cl_flag_reset_samples);
	cl_renderer_render(gui->renderer);
}

void 				gui_signal_camera_filter_aperture_size
					(GtkWidget *widget, gpointer ptr)
{
	t_gui			*gui;

	gui = (t_gui *)ptr;
	gui->renderer->data.camera->aperture_size =
		(RT_F)strtod(gtk_entry_get_text(gui->camera->aperture_size), NULL);
	cl_renderer_flag_set(gui->renderer, cl_flag_update_camera);
	cl_renderer_flag_set(gui->renderer, cl_flag_reset_samples);
	cl_renderer_render(gui->renderer);
}