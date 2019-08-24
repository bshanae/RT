#include "gui_signal_x.h"

void 				gui_signal_camera_rotation_x
					(GtkWidget *widget, gpointer ptr)
{
	t_gui			*gui;

	gui = (t_gui *)ptr;
	gui->renderer->data.camera->rotation.x =
		(RT_F)strtod(gtk_entry_get_text(gui->camera->rotation_x), NULL);
	camera_apply(gui->renderer->data.camera);
	cl_renderer_flag_set(gui->renderer, cl_flag_update_camera);
	cl_renderer_flag_set(gui->renderer, cl_flag_reset_samples);
	cl_renderer_render(gui->renderer);
}

void 				gui_signal_camera_rotation_y
					(GtkWidget *widget, gpointer ptr)
{
	t_gui			*gui;

	gui = (t_gui *)ptr;
	gui->renderer->data.camera->rotation.y =
		(RT_F)strtod(gtk_entry_get_text(gui->camera->rotation_y), NULL);
	camera_apply(gui->renderer->data.camera);
	cl_renderer_flag_set(gui->renderer, cl_flag_update_camera);
	cl_renderer_flag_set(gui->renderer, cl_flag_reset_samples);
	cl_renderer_render(gui->renderer);
}

void 				gui_signal_camera_rotation_z
					(GtkWidget *widget, gpointer ptr)
{
	t_gui			*gui;

	gui = (t_gui *)ptr;
	gui->renderer->data.camera->rotation.z =
		(RT_F)strtod(gtk_entry_get_text(gui->camera->rotation_z), NULL);
	camera_apply(gui->renderer->data.camera);
	cl_renderer_flag_set(gui->renderer, cl_flag_update_camera);
	cl_renderer_flag_set(gui->renderer, cl_flag_reset_samples);
	cl_renderer_render(gui->renderer);
}