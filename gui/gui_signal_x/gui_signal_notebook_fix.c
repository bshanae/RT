#include "gui_signal_x.h"

void				gui_signal_notebook_fix
					(GtkNotebook *notebook, GtkWidget *page,
					guint page_num, gpointer ptr)
{
	t_gui			*gui;

	gui = (t_gui *)ptr;
	gtk_widget_grab_focus(GTK_WIDGET(gui->notebook_fix[page_num]));
}