#include "gui_signal_x.h"

void 				gui_signal_exit(GtkWidget *widget, gpointer ptr)
{
	t_gui			*gui;

	gui = (t_gui *)ptr;
	gui_queue_finish(gui->queue);
	gtk_main_quit();
}