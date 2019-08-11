#include "gui_signal_x.h"

gboolean			gui_signal_key
					(GtkWidget *widget, GdkEventKey *key, gpointer ptr)
{
	t_gui			*gui;

	gui = (t_gui *)ptr;
	if (key->keyval == GDK_KEY_Escape)
		gui_signal_exit(widget, ptr);
	return (FALSE);
}