#include "gui_signal_x.h"

void 				gui_signal_scene_edit_name
					(GtkWidget *widget, gpointer ptr)
{
	t_gui			*gui;

	gui = (t_gui *)ptr;
	gtk_widget_set_opacity(GTK_WIDGET(gui->scene->edit->control), 1.);
}