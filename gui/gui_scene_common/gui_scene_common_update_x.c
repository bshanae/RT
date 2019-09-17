#include "gui_scene_common.h"

void 				gui_scene_common_update_full
					(t_gui_scene_common *gui, t_scene *scene)
{
	int 			i;

	i = 0;
	gtk_list_store_clear(gui->full);
	while (i < scene->objects_length)
	{
		if (!scene->objects[i].name[0])
			gui_scene_common_gen_name(gui, scene->objects + i);
		if (object_flag_get(scene->objects + i) & *scene->current_mod)
			gui_scene_common_add_to_list(gui->full, scene->objects + i);
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
	if (*scene->current_mod == RT_OBJECT_RM)
		return ;
	if (!gtk_tree_model_get_iter_first(model, &iter_full))
		return ;
	gtk_list_store_clear(gui->limited_main);
	gtk_list_store_clear(gui->limited_limit);
	while (1)
	{
		gtk_tree_model_get(model, &iter_full, gui_objects_column_id, &i, -1);
		if (object_flag_get(scene->objects + i) & RT_OBJECT_LIMITABLE)
			gui_scene_common_add_to_list(gui->limited_main, scene->objects + i);
		else if (object_flag_get(scene->objects + i) & RT_OBJECT_LIMITING)
			gui_scene_common_add_to_list(gui->limited_limit, scene->objects + i);
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
	if (*scene->current_mod == RT_OBJECT_RT)
		return ;
	if (!gtk_tree_model_get_iter_first(model, &iter_full))
		return ;
	gtk_list_store_clear(gui->csg);
	while (1)
	{
		gtk_tree_model_get(model, &iter_full, gui_objects_column_id, &i, -1);
		if (object_flag_get(scene->objects + i) & RT_OBJECT_CSG)
			gui_scene_common_add_to_list(gui->csg, scene->objects + i);
		i++;
		if (!gtk_tree_model_iter_next(model, &iter_full))
			break ;
	}
}

void 				gui_scene_common_update_types
					(t_gui_scene_common *gui, t_scene *scene)
{
	GtkTreeIter		iter_list;
	t_object_type	iter_type;
	t_object		temp;

	gtk_list_store_clear(gui->types);
	iter_type = 0;
	while (iter_type < object_type_end)
	{
		temp.type = iter_type;
		if (object_flag_get(&temp) & *scene->current_mod)
		{
			gtk_list_store_append(gui->types, &iter_list);
			gtk_list_store_set(gui->types, &iter_list,
				gui_types_column_id, iter_type,
				gui_types_column_name, object_translate(iter_type), -1);
		}
		iter_type++;
	}
}

void 				gui_scene_common_update_textures
					(t_gui_scene_common *gui, t_scene *scene)
{
	GtkTreeIter		iter_list;
	int 			i;

	gtk_list_store_clear(gui->textures);
	i = 0;
	while (i <= scene->texture.textures_number)
	{
		gtk_list_store_append(gui->textures, &iter_list);
		gtk_list_store_set(gui->textures, &iter_list,
			gui_textures_column_id, i,
			gui_textures_column_name, scene->texture.name[i], -1);
		i++;
	}
}


void 				gui_scene_common_update_all
					(t_gui_scene_common *gui, t_scene *scene)
{
	gui->reset_generator = 1;
	gui_scene_common_gen_name(gui, NULL);
	gui_scene_common_update_full(gui, scene);
	gui_scene_common_update_limited(gui, scene);
	gui_scene_common_update_csg(gui, scene);
	gui_scene_common_update_textures(gui, scene);
	gui_scene_common_update_types(gui, scene);
}