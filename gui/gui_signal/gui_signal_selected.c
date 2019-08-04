#include "gui_signal.h"

void				gui_signal_selected(
					GtkTreeSelection *select,
					gpointer ptr)
{
	t_gui			*gui;
	GtkTreeModel	*model;

	gui = (t_gui *)ptr;
	if (!gtk_tree_selection_get_selected(gui->list->select,
		&model, &gui->list->iter))
		return ;
	gtk_tree_model_get(model,
			&gui->list->iter, gl_id, &gui->object->current_id, -1);
	if (gui->renderer->scene->objects[gui->object->current_id].type == object_sphere)
		gui_sphere_load(&gui->object->sphere,
				gui->renderer->scene->objects + gui->object->current_id);
}