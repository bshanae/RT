#include "gui_scene_common.h"

static t_rt_bool	static_is_current_mod(int rm_mod, t_object *object)
{
	if (!rm_mod && (object_flag_get(object) & RT_OBJECT_RT))
		return (rt_true);
	if (rm_mod && (object_flag_get(object) & RT_OBJECT_RM))
		return (rt_true);
	return (rt_false);
}

void 				gui_scene_common_update_full
					(t_gui_scene_common *gui, t_scene *scene, int rm_mod)
{
	int 			i;
	GtkTreeIter		iter;

	i = 0;
	gtk_list_store_clear(gui->full);
	while (i < scene->objects_length)
	{
		if (!scene->objects[i].name[0])
			gui_scene_common_gen_name(gui, scene->objects + i);
		if (static_is_current_mod(rm_mod, scene->objects + i) == rt_true)
		{
			gtk_list_store_append(gui->full, &iter);
			gtk_list_store_set(gui->full, &iter,
				gui_scene_column_id, scene->objects[i].id,
				gui_scene_column_name, scene->objects[i].name, -1);
		}
		i++;
	}
}

void				gui_scene_common_update_limited
	(t_gui_scene_common *gui, t_scene *scene)
{
	int 			i;
	GtkTreeIter		iter;

	i = 0;
	gtk_list_store_clear(gui->limited_main);
	gtk_list_store_clear(gui->limited_limit);
	while (i < scene->objects_length)
	{
		if (object_flag_get(scene->objects + i) & RT_OBJECT_LIMITABLE)
		{
			gtk_list_store_append(gui->limited_main, &iter);
			gtk_list_store_set(gui->limited_main, &iter,
				gui_scene_column_id, scene->objects[i].id,
				gui_scene_column_name, scene->objects[i].name, -1);
		}
		else if (object_flag_get(scene->objects + i) & RT_OBJECT_LIMITING)
		{
			gtk_list_store_append(gui->limited_limit, &iter);
			gtk_list_store_set(gui->limited_limit, &iter,
				gui_scene_column_id, scene->objects[i].id,
				gui_scene_column_name, scene->objects[i].name, -1);
		}
		i++;
	}
}

void 				gui_scene_common_update_csg
					(t_gui_scene_common *gui, t_scene *scene)
{
	int 			i;
	GtkTreeIter		iter;

	i = 0;
	gui_scene_common_gen_name(gui, scene->objects + i);
	gtk_list_store_clear(gui->csg);
	while (i < scene->objects_length)
	{
		if (object_flag_get(scene->objects + i) & RT_OBJECT_CSG)
		{
			gtk_list_store_append(gui->csg, &iter);
			gtk_list_store_set(gui->csg, &iter,
				 gui_scene_column_id, scene->objects[i].id,
				gui_scene_column_name, scene->objects[i].name, -1);
		}
		i++;
	}
}

void 				gui_scene_common_update_all
					(t_gui_scene_common *gui, t_scene *scene, int rm_mod)
{
	gui_scene_common_update_full(gui, scene, rm_mod);
	gui_scene_common_update_limited(gui, scene);
	gui_scene_common_update_csg(gui, scene);
}