#include "gui_signal_x.h"

void				gui_signal_camera_apply
	(GtkWidget *widget, gpointer ptr)
{
	t_gui			*gui;

	gui = (t_gui *)ptr;
	gui_camera_apply(gui->camera, gui->renderer->data.camera);
	gtk_widget_set_opacity(GTK_WIDGET(gui->camera->control), 0.);
}