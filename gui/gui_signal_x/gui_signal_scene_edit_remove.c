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
	if (gtk_list_store_iter_is_valid(edit->common->full, &edit->iter))
		scene_object_remove(gui->renderer->data.scene, edit->current_id);
	else
		return ;
	gui_scene_common_update_all(gui->scene->common);
	cl_renderer_flag_set(gui->renderer, cl_flag_update_scene);
	cl_renderer_flag_set(gui->renderer, cl_flag_reset_samples);
	gui_queue_push(gui->queue);

}