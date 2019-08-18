#include "gui_signal_connect.h"

void 				gui_signal_object_edit_plane_name
					(GtkWidget *widget, gpointer ptr)
{
	t_gui			*gui;
	t_object		*object;

	gui = (t_gui *)ptr;
	if (gui->scene->edit->current_id == -1)
		return ;
	object = gui->renderer->data_host.scene->objects +
			 gui->scene->edit->current_id;
	ft_strcpy(object->name, gtk_entry_get_text(GTK_ENTRY(widget)));
	gtk_list_store_set(
		gui->scene->edit->list, &gui->scene->edit->iter,
		scene_edit_object_name, object->name, -1);
	gui->renderer->flags.update_scene = 1;
}