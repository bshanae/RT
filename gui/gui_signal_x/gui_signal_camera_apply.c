#include "gui_signal_x.h"

void				gui_signal_camera_apply
	(GtkWidget *widget, gpointer ptr)
{
	t_gui			*gui;

	gui = (t_gui *)ptr;
	gui_camera_apply(gui->camera, gui->renderer->data.camera);
	gui_control_hide(&gui->camera->control);
	cl_renderer_flag_set(gui->renderer, cl_flag_update_camera);
	cl_renderer_flag_set(gui->renderer, cl_flag_reset_samples);
	gui_queue_push(gui->queue);

}