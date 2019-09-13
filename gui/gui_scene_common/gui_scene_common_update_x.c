#include "gui_scene_common.h"

static t_rt_bool	static_is_current_mod(int rm_mod, t_object *object)
{
	if (!rm_mod && (object_flag_get(object) & RT_OBJECT_RT))
		return (rt_true);
	if (rm_mod && (object_flag_get(object) & RT_OBJECT_RM))
		return (rt_true);
	return (rt_false);
}

static void			static_add_to_list(GtkListStore *list, t_object *object)
{
	GtkTreeIter		iter;

	gtk_list_store_append(list, &iter);
	gtk_list_store_set(list, &iter,
		gui_scene_column_id, object->id,
		gui_scene_column_name, object->name, -1);
}

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
		if (static_is_current_mod(rm_mod, scene->objects + i) == rt_true)
			static_add_to_list(gui->full, scene->objects + i);
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
			static_add_to_list(gui->limited_main, scene->objects + i);
		else if (object_flag_get(scene->objects + i) & RT_OBJECT_LIMITING)
			static_add_to_list(gui->limited_limit, scene->objects + i);
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
			static_add_to_list(gui->csg, scene->objects + i);
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