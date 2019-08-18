#include "gui_signal_x.h"

void 				gui_signal_scene_edit_select
					(GtkWidget *widget, gpointer ptr)
{
	t_gui			*gui;
	GtkTreeModel	*model;
	t_object		*object;

	gui = (t_gui *)ptr;
	gtk_tree_selection_get_selected(gui->scene->edit->selection,
		&model, &gui->scene->edit->iter);
	if (gui->scene->edit->current_object)
		gtk_widget_hide(GTK_WIDGET(gui->scene->edit->current_object));
	gtk_tree_model_get(model, &gui->scene->edit->iter,
		scene_edit_object_id, &gui->scene->edit->current_id ,-1);
	object = gui->renderer->data.scene->objects +
		gui->scene->edit->current_id;
	gui->scene->edit->current_object =
		gui_scene_edit_get_object(gui->scene->edit, object->type);
	gui_scene_edit_show(gui->scene->edit, object);
}