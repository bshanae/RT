#include "gui_signal_x.h"

void 				gui_signal_exit(GtkWidget *widget, gpointer ptr)
{
	widget = NULL;
	ptr = NULL;
	gtk_main_quit();
}