#include "gui_signal_x.h"

void					gui_signal_scene_edit_remove
						(GtkWidget *widget, gpointer ptr)
{
	t_gui				*gui;
	t_gui_scene_edit	*edit;

	gui = (t_gui *)ptr;
	edit = gui->scene->edit;
	if (gtk_list_store_iter_is_valid(edit->list, &edit->iter))
	{
		scene_remove_object(gui->renderer->data_host.scene, edit->current_id);
		gtk_list_store_remove(edit->list, &edit->iter);
	}
}