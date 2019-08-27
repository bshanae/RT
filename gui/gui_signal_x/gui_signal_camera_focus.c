#include "gui_signal_x.h"

gboolean			gui_signal_camera_focus
					(GtkWidget *widget, gboolean state, gpointer ptr)
{
	t_gui			*gui;

	gui = (t_gui *)ptr;
	gui->renderer->data.camera->focus = state;
	if (state)
		gui_camera_focus_enable(gui->camera);
	else
		gui_camera_focus_disable(gui->camera);
	cl_renderer_flag_set(gui->renderer, cl_flag_update_camera);
	cl_renderer_flag_set(gui->renderer, cl_flag_reset_samples);
	cl_renderer_render(gui->renderer);
	return (FALSE);
}