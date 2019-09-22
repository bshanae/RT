#include "gui_signal_x.h"

void 				gui_signal_camera_main_reset
					(GtkWidget *widget, gpointer ptr)
{
	t_gui			*gui;

	gui = (t_gui *)ptr;
	cl_renderer_camera_reset(gui->renderer);
	gui_camera_show(gui->camera, gui->renderer->data.camera);
}

void 				gui_signal_camera_main_save
					(GtkWidget *widget, gpointer ptr)
{
	t_gui			*gui;

	gui = (t_gui *)ptr;
	cl_renderer_camera_save(gui->renderer);
	gui_camera_show(gui->camera, gui->renderer->data.camera);
}