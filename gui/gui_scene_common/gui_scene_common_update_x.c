#include "gui_scene_common.h"

void 				gui_scene_common_update_full
					(t_gui_scene_common *gui, t_scene *scene, int rm_mod)
{
	int 			i;

	i = 0;
	gtk_list_store_clear(gui->full);
	while (i < scene->objects_length)
	{
		if (!scene->objects[i].name[0])
			gui_scene_common_gen_name(gui, scene->objects + i);
		if (gui_scene_common_func_a(rm_mod, scene->objects + i) == rt_true)
			gui_scene_common_func_b(gui->full, scene->objects + i);
		i++;
	}
}

void				gui_scene_common_update_limited
					(t_gui_scene_common *gui, t_scene *scene)
{
	GtkTreeModel	*model;
	int 			i;
	GtkTreeIter		iter_full;

	model = GTK_TREE_MODEL(gui->full);
	if (!gtk_tree_model_get_iter_first(model, &iter_full))
		return ;
	gtk_list_store_clear(gui->limited_main);
	gtk_list_store_clear(gui->limited_limit);
	while (1)
	{
		gtk_tree_model_get(model, &iter_full, gui_scene_column_id, &i, -1);
		if (object_flag_get(scene->objects + i) & RT_OBJECT_LIMITABLE)
			gui_scene_common_func_b(gui->limited_main, scene->objects + i);
		else if (object_flag_get(scene->objects + i) & RT_OBJECT_LIMITING)
			gui_scene_common_func_b(gui->limited_limit, scene->objects + i);
		if (!gtk_tree_model_iter_next(model, &iter_full))
			break ;
	}
}

void 				gui_scene_common_update_csg
					(t_gui_scene_common *gui, t_scene *scene)
{
	GtkTreeModel	*model;
	int 			i;
	GtkTreeIter		iter_full;

	model = GTK_TREE_MODEL(gui->full);
	if (!gtk_tree_model_get_iter_first(model, &iter_full))
		return ;
	gtk_list_store_clear(gui->csg);
	while (1)
	{
		gtk_tree_model_get(model, &iter_full, gui_scene_column_id, &i, -1);
		if (object_flag_get(scene->objects + i) & RT_OBJECT_CSG)
			gui_scene_common_func_b(gui->csg, scene->objects + i);
		i++;
		if (!gtk_tree_model_iter_next(model, &iter_full))
			break ;
	}
}

void 				gui_scene_common_update_all
					(t_gui_scene_common *gui, t_scene *scene, int rm_mod)
{
	gui->reset_generator = 1;
	gui_scene_common_gen_name(gui, NULL);
	gui_scene_common_update_full(gui, scene, rm_mod);
	gui_scene_common_update_limited(gui, scene);
	gui_scene_common_update_csg(gui, scene);
}