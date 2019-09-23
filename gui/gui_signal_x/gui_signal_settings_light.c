#include "gui_signal_x.h"

void						gui_signal_settings_light
							(GtkWidget *widget, gpointer ptr)
{
	t_gui 					*gui;
	t_rt_settings			*settings;
	int						state[2];

	gui = (t_gui *) ptr;
	settings = &gui->renderer->data.settings;
	state[0] = gtk_toggle_button_get_active(gui->settings->light_basic);
	state[1] = gtk_toggle_button_get_active(gui->settings->light_area);
	settings->light_mod = state[0] ? rt_light_basic : rt_light_area;
	cl_renderer_flag_set(gui->renderer, cl_flag_update_settings);
	cl_renderer_flag_set(gui->renderer, cl_flag_reset_samples);
	gui_queue_push(gui->queue);
}