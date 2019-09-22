#include "gui_scene_edit.h"

void 				gui_scene_edit_background_get
					(t_gui_scene_edit *edit, t_scene *scene)
{
	GtkTreeModel	*model;
	int 			i;
	GtkTreeIter		iter;

	model = GTK_TREE_MODEL(edit->common->background);
	if (!gtk_tree_model_get_iter_first(model, &iter))
		return ;
	while (1)
	{
		gtk_tree_model_get(model, &iter, gui_list_column_id, &i, -1);
		if (i == scene->background)
		{
			gtk_combo_box_set_active_iter(edit->background_combo, &iter);
			return ;
		}
		if (!gtk_tree_model_iter_next(model, &iter))
			break ;
	}
	rt_raise_warning("GUI Editor : background id not found");
}

void 				gui_scene_edit_background_set
					(t_gui_scene_edit *edit, t_scene *scene)
{
	GtkTreeIter			iter;

	if (gtk_combo_box_get_active_iter(edit->background_combo, &iter))
		gtk_tree_model_get(GTK_TREE_MODEL(edit->common->background), &iter,
			gui_list_column_id, &scene->background, -1);
	else
		rt_raise_warning("GUI Editor : no background selected\n");
}