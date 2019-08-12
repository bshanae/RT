#include "gui_signal_x.h"

void				gui_signal_scene_add_cancel
					(GtkWidget *widget, gpointer ptr)
{
	t_gui			*gui;

	gui = (t_gui *)ptr;
	gtk_dialog_response(gui->scene->add->dialog, GTK_RESPONSE_CANCEL);
}