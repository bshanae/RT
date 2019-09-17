#include "gui_signal_x.h"

gboolean			gui_signal_settings_illumination_state
					(GtkSwitch *widget, gboolean state, gpointer ptr)
{
	t_gui			*gui;

	gui = (t_gui *)ptr;
	gui->renderer->data.settings.illumination = state;
	cl_renderer_flag_set(gui->renderer, cl_flag_update_settings);
	cl_renderer_flag_set(gui->renderer, cl_flag_reset_samples);
	gui_queue_push(gui->queue);
	return (FALSE);
}