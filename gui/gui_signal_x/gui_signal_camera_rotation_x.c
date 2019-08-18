#include "gui_signal_x.h"

void 				gui_signal_camera_rotation_x
					(GtkWidget *widget, gpointer ptr)
{
	t_gui			*gui;

	gui = (t_gui *)ptr;
	gui->renderer->data_host.camera->rotation.x =
		(RT_F)strtod(gtk_entry_get_text(gui->camera->rotation_x), NULL);
	camera_apply(gui->renderer->data_host.camera);
	gui->renderer->flags.update_camera = 1;
	cl_renderer_reset_samples(gui->renderer);
	cl_renderer_render(gui->renderer);
}

void 				gui_signal_camera_rotation_y
					(GtkWidget *widget, gpointer ptr)
{
	t_gui			*gui;

	gui = (t_gui *)ptr;
	gui->renderer->data_host.camera->rotation.y =
		(RT_F)strtod(gtk_entry_get_text(gui->camera->rotation_y), NULL);
	camera_apply(gui->renderer->data_host.camera);
	gui->renderer->flags.update_camera = 1;
	cl_renderer_reset_samples(gui->renderer);
	cl_renderer_render(gui->renderer);
}

void 				gui_signal_camera_rotation_z
					(GtkWidget *widget, gpointer ptr)
{
	t_gui			*gui;

	gui = (t_gui *)ptr;
	gui->renderer->data_host.camera->rotation.z =
		(RT_F)strtod(gtk_entry_get_text(gui->camera->rotation_z), NULL);
	camera_apply(gui->renderer->data_host.camera);
	gui->renderer->flags.update_camera = 1;
	cl_renderer_reset_samples(gui->renderer);
	cl_renderer_render(gui->renderer);
}