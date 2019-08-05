#include "gui_signal.h"

gboolean			gui_s_key
					(GtkWindow *window, GdkEventKey *key, gpointer ptr)
{
	t_gui			*gui;

	gui = (t_gui *)ptr;
	if (key->keyval == GDK_KEY_Escape)
		gtk_main_quit();
	return (FALSE);
}