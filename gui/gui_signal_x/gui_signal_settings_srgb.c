#include "gui_signal_x.h"

gboolean			gui_signal_settings_srgb
					(GtkWidget *widget, gboolean state, gpointer ptr)
{
	t_gui			*gui;

	gui = (t_gui *)ptr;
	gui->renderer->data.settings.srgb = state;
	return (FALSE);
}