#include "gui_signal_x.h"

void 				gui_signal_camera_position_x
					(GtkWidget *widget, gpointer ptr)
{
	t_gui			*gui;

	gui = (t_gui *)ptr;
	gui->renderer->data_host.camera->position.x =
		(RT_F)strtod(gtk_entry_get_text(gui->camera->position_x), NULL);
	gui->renderer->flags.update_camera = 1;
	cl_renderer_reset_samples(gui->renderer);
}

void 				gui_signal_camera_position_y
	(GtkWidget *widget, gpointer ptr)
{
	t_gui			*gui;

	gui = (t_gui *)ptr;
	gui->renderer->data_host.camera->position.y =
		(RT_F)strtod(gtk_entry_get_text(gui->camera->position_y), NULL);
	gui->renderer->flags.update_camera = 1;
	cl_renderer_reset_samples(gui->renderer);
}

void 				gui_signal_camera_position_z
	(GtkWidget *widget, gpointer ptr)
{
	t_gui			*gui;

	gui = (t_gui *)ptr;
	gui->renderer->data_host.camera->position.z =
		(RT_F)strtod(gtk_entry_get_text(gui->camera->position_z), NULL);
	gui->renderer->flags.update_camera = 1;
	cl_renderer_reset_samples(gui->renderer);
}
