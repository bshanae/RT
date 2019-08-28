#include "gui_signal_x.h"

void				gui_signal_camera_filter
					(GtkWidget *widget, gpointer ptr)
{
	t_gui			*gui;
	t_camera		*camera;
	int 			state[2];

	gui = (t_gui *)ptr;
	camera = gui->renderer->data.camera;
	state[0] = gtk_toggle_button_get_active(gui->camera->filter_cartoon);
	state[1] = gtk_toggle_button_get_active(gui->camera->filter_sepia);
	if (state[0] == camera->filter_cartoon && state[1] == camera->filter_sepia)
		return ;
	camera->filter_cartoon = state[0];
	camera->filter_sepia = state[1];
	cl_renderer_flag_set(gui->renderer, cl_flag_update_camera);
	cl_renderer_flag_set(gui->renderer, cl_flag_reset_samples);
	gui_queue_push(gui->queue);

}


