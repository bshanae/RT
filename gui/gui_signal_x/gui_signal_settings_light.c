#include "gui_signal_x.h"

void						gui_signal_settings_light
							(GtkWidget *widget, gpointer ptr)
{
	t_gui 					*gui;
	int						state[2];

	gui = (t_gui *) ptr;
	state[0] = gtk_toggle_button_get_active(gui->settings->light_basic);
	state[1] = gtk_toggle_button_get_active(gui->settings->light_area);
	cl_renderer_change_light_mod(gui->renderer,
		state[0] ? rt_light_basic : rt_light_area);
	gui_scene_common_update_all(gui->scene->common);
	gui_camera_show(gui->camera);
	gui_queue_push(gui->queue);
}