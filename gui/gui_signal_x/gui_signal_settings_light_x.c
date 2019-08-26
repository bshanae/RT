#include "gui_signal_x.h"

gboolean			gui_signal_settings_light_basic
					(GtkWidget *widget, gboolean state, gpointer ptr)
{
	t_gui		*gui;

	gui = (t_gui *)ptr;
	gui->renderer->data.settings.light_basic = state;
	return (FALSE);
}

gboolean			gui_signal_settings_light_area
					(GtkWidget *widget, gboolean state, gpointer ptr)
{
	t_gui		*gui;

	gui = (t_gui *)ptr;
	gui->renderer->data.settings.light_area = state;
	return (FALSE);
}
