#include "gui_signal_x.h"

void 				gui_signal_settings_pt_russian
					(GtkWidget *widget, gboolean state, gpointer ptr)
{
	t_gui			*gui;

	gui = (t_gui *)ptr;
	gui->renderer->data.settings.russian_mod = state;
}