#include "gui_signal_x.h"

void 				gui_signal_scene_edit_select
					(GtkWidget *widget, gpointer ptr)
{
	t_gui			*gui;
	GtkTreeModel	*model;
	t_object		*object;

	gui = (t_gui *)ptr;
	if (!gtk_tree_selection_get_selected(gui->scene->edit->selection,
		&model, &gui->scene->edit->iter))
		return ;
	gtk_tree_model_get(model, &gui->scene->edit->iter,
		scene_edit_object_id, &gui->scene->edit->current_id ,-1);
	object = gui->renderer->data.scene->objects + gui->scene->edit->current_id;
	gui_scene_edit_show(gui->scene->edit, object);
	gtk_widget_set_opacity(GTK_WIDGET(gui->scene->edit->control), 0.);
}