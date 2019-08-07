#include "gui_signal.h"

gboolean			gui_s_key
					(GtkWindow *window, GdkEventKey *key, gpointer ptr)
{
	t_gui			*gui;

	gui = (t_gui *)ptr;
	if (key->keyval == GDK_KEY_Escape)
		gtk_main_quit();
	else if (key->keyval == GDK_KEY_Return)
	{
		cl_renderer_render(gui->renderer);
		gtk_main_iteration();
	}
	return (FALSE);
}