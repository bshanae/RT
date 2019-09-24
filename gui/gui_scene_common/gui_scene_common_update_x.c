#include "gui_scene_common.h"

static int 			static_check_mod(t_gui_scene_common *gui, t_object *object)
{
	const UINT		flag = object_flag_get(object);

	if (flag & RT_OBJECT_LIGHT && *gui->ptr_light != rt_light_basic)
		return (0);
	return ((int)(flag & *gui->ptr_scene->current_mod));
}

void 				gui_scene_common_update_full(t_gui_scene_common *gui)
{
	int 			i;

	rt_assert_critical(gui->connected, "GUI Common : Not connected");
	i = 0;
	gtk_list_store_clear(gui->full);
	while (i < gui->ptr_scene->objects_length)
	{
		if (!gui->ptr_scene->objects[i].name[0])
			gui_scene_common_gen_name(gui, gui->ptr_scene->objects + i);
		if (static_check_mod(gui, gui->ptr_scene->objects + i))
			gui_scene_common_add_to_list(gui->full, gui->ptr_scene->objects + i);
		i++;

	}
}

void				gui_scene_common_update_limited(t_gui_scene_common *gui)
{
	GtkTreeModel	*model;
	int 			i;
	GtkTreeIter		iter_full;
	t_object		temp;

	rt_assert_critical(gui->connected, "GUI Common : Not connected");
	model = GTK_TREE_MODEL(gui->full);
	if (*gui->ptr_scene->current_mod == RT_OBJECT_RM)
		return ;
	if (!gtk_tree_model_get_iter_first(model, &iter_full))
		return ;
	gtk_list_store_clear(gui->limited_main);
	gtk_list_store_clear(gui->limited_limit);
	ft_strcpy(temp.name, "None");
	temp.id = -1;
	gui_scene_common_add_to_list(gui->limited_main, &temp);
	gui_scene_common_add_to_list(gui->limited_limit, &temp);
	while (1)
	{
		gtk_tree_model_get(model, &iter_full, gui_list_column_id, &i, -1);
		if (object_flag_get(gui->ptr_scene->objects + i) & RT_OBJECT_LIMITABLE)
			gui_scene_common_add_to_list(gui->limited_main, gui->ptr_scene->objects + i);
		else if (object_flag_get(gui->ptr_scene->objects + i) & RT_OBJECT_LIMITING)
			gui_scene_common_add_to_list(gui->limited_limit, gui->ptr_scene->objects + i);
		if (!gtk_tree_model_iter_next(model, &iter_full))
			break ;
	}
}

void 				gui_scene_common_update_csg(t_gui_scene_common *gui)
{
	GtkTreeModel	*model;
	int 			i;
	GtkTreeIter		iter_full;
	t_object		temp;

	rt_assert_critical(gui->connected, "GUI Common : Not connected");
	model = GTK_TREE_MODEL(gui->full);
	if (*gui->ptr_scene->current_mod == RT_OBJECT_RT)
		return ;
	if (!gtk_tree_model_get_iter_first(model, &iter_full))
		return ;
	gtk_list_store_clear(gui->csg);
	ft_strcpy(temp.name, "None");
	temp.id = -1;
	gui_scene_common_add_to_list(gui->csg, &temp);
	while (1)
	{
		gtk_tree_model_get(model, &iter_full, gui_list_column_id, &i, -1);
		if (object_flag_get(gui->ptr_scene->objects + i) & RT_OBJECT_CSG)
			gui_scene_common_add_to_list(gui->csg, gui->ptr_scene->objects + i);
		i++;
		if (!gtk_tree_model_iter_next(model, &iter_full))
			break ;
	}
}

void 				gui_scene_common_update_types(t_gui_scene_common *gui)
{
	GtkTreeIter		iter_list;
	t_object_type	iter_type;
	t_object		temp;

	rt_assert_critical(gui->connected, "GUI Common : Not connected");
	gtk_list_store_clear(gui->types);
	iter_type = 0;
	while (iter_type < object_type_end)
	{
		temp.type = iter_type;
		if (static_check_mod(gui, &temp))
		{
			gtk_list_store_append(gui->types, &iter_list);
			gtk_list_store_set(gui->types, &iter_list,
				gui_list_column_id, iter_type,
				gui_list_column_name, object_translate(iter_type), -1);
		}
		iter_type++;
	}
}

void 				gui_scene_common_update_textures(t_gui_scene_common *gui)
{
	GtkTreeIter		iter_list;
	int 			i;

	rt_assert_critical(gui->connected, "GUI Common : Not connected");
	gtk_list_store_clear(gui->textures);
	gtk_list_store_append(gui->textures, &iter_list);
	gtk_list_store_set(gui->textures, &iter_list,
		gui_list_column_id, -1,
		gui_list_column_name, "None", -1);
	i = 0;
	while (i <= gui->ptr_scene->texture.textures_number)
	{
		gtk_list_store_append(gui->textures, &iter_list);
		gtk_list_store_set(gui->textures, &iter_list,
			gui_list_column_id, i,
			gui_list_column_name, gui->ptr_scene->texture.name[i], -1);
		i++;
	}
}

void 				gui_scene_common_update_background
					(t_gui_scene_common *gui)
{
	t_rt_background	i;
	GtkTreeIter		iter;

	i = 0;
	gtk_list_store_clear(gui->full);
	while (i < rt_background_end)
	{
		gtk_list_store_append(gui->background, &iter);
		gtk_list_store_set(gui->background, &iter,
			gui_list_column_id, i,
			gui_list_column_name, rt_background_translate(i), -1);
		i++;

	}
}

void 				gui_scene_common_update_all(t_gui_scene_common *gui)
{
	rt_assert_critical(gui->connected, "GUI Common : Not connected");
	gui->reset_generator = rt_true;
	gui_scene_common_gen_name(gui, NULL);
	gui_scene_common_update_full(gui);
	gui_scene_common_update_limited(gui);
	gui_scene_common_update_csg(gui);
	gui_scene_common_update_textures(gui);
	gui_scene_common_update_types(gui);
}