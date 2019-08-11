#include "gui_signal_x.h"

void 				gui_signal_scene_edit_select
					(GtkWidget *widget, gpointer ptr)
{
	t_gui			*gui;
	GtkTreeModel	*model;
	GtkTreeIter		iter;
	t_object		*object;

	gui = (t_gui *)ptr;
	if (!gtk_tree_selection_get_selected(gui->scene->edit->selection,
		&model, &iter))
		return ;
	if (gui->scene->edit->current_box)
		gtk_widget_hide(GTK_WIDGET(gui->scene->edit->current_box));
	gtk_tree_model_get(model, &iter,
		scene_edit_object_id, &gui->scene->edit->current_id ,-1);
	object =
		gui->renderer->data_host.scene->objects + gui->scene->edit->current_id;
	if (object->type == object_sphere)
	{
		gui_object_edit_sphere_load(&gui->scene->edit->sphere, object);
		gui->scene->edit->current_box = gui->scene->edit->sphere.box;
	}
	if (object->type == object_plane)
	{
		gui_object_edit_plane_load(&gui->scene->edit->plane, object);
		gui->scene->edit->current_box = gui->scene->edit->plane.box;
	}
	gtk_widget_show(GTK_WIDGET(gui->scene->edit->current_box));
}