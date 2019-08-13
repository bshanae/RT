#include "gui_signal_x.h"

void					gui_signal_scene_edit_remove
						(GtkWidget *widget, gpointer ptr)
{
	t_gui				*gui;
	t_gui_scene_edit	*edit;
	int 				response;

	gui = (t_gui *)ptr;
	edit = gui->scene->edit;
	response = gtk_dialog_run(gui->scene->edit->remove_dialog);
	gtk_widget_hide(GTK_WIDGET(gui->scene->edit->remove_dialog));
	if (response != GTK_RESPONSE_YES)
		return ;
	if (gtk_list_store_iter_is_valid(edit->list, &edit->iter))
	{
		scene_remove_object(gui->renderer->data_host.scene, edit->current_id);
		gtk_list_store_remove(edit->list, &edit->iter);
	}
}