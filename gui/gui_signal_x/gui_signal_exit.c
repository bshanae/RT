#include "gui_signal_x.h"

void 				gui_signal_exit(GtkWidget *widget, gpointer ptr)
{
	gtk_main_quit();
}