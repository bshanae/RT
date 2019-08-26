#include "gui_signal_x.h"

void				gui_signal_scene_edit_reset
					(GtkWidget *widget, gpointer ptr)
{
	t_gui			*gui;
	t_object		*object;

	gui = (t_gui *)ptr;
	object = gui->renderer->data.scene->objects + gui->scene->edit->current_id;
	gui_scene_edit_show(gui->scene->edit, object);
	gtk_widget_set_opacity(GTK_WIDGET(gui->scene->edit->control), 0.);
}