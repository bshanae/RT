#include "gui_signal_x.h"

gboolean			gui_signal_settings_motion_blur
					(GtkWidget *widget, gboolean state, gpointer ptr)
{
	t_gui			*gui;

	gui = (t_gui *)ptr;
	gui->renderer->data.settings.motion_blur = state;
	cl_renderer_flag_set(gui->renderer, cl_flag_update_settings);
	cl_renderer_flag_set(gui->renderer, cl_flag_reset_samples);
	return (FALSE);
}