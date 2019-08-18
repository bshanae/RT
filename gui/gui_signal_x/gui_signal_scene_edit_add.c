#include "gui_signal_x.h"

void				gui_signal_scene_edit_add
					(GtkWidget *widget, gpointer ptr)
{
	t_gui			*gui;
	int				response;
	GtkTreeIter		iter;
	t_object		*new_object;

	gui = (t_gui *)ptr;
	gtk_entry_set_placeholder_text(gui->scene->add->name,
		gui_scene_add_gen_name(gui->scene->add));
	gtk_widget_grab_focus(GTK_WIDGET(gui->scene->add->type_combo));
	response = gtk_dialog_run(gui->scene->add->dialog);
	if (response == GTK_RESPONSE_YES)
	{
		new_object = gui->renderer->data_host.scene->objects +
			gui->renderer->data_host.scene->objects_length - 1;
		gtk_list_store_append(gui->scene->edit->list, &iter);
		gtk_list_store_set(
			gui->scene->edit->list, &iter,
			scene_edit_object_id, new_object->id,
			scene_edit_object_name, new_object->name,
			// todo add icon
			scene_edit_type_id, new_object->type,
			-1);
	}
	gtk_widget_hide(GTK_WIDGET(gui->scene->add->dialog));
}