#include "gui_scene_common.h"

t_rt_bool		 gui_scene_common_func_a(int rm_mod, t_object *object)
{
	if (!rm_mod && (object_flag_get(object) & RT_OBJECT_RT))
		return (rt_true);
	if (rm_mod && (object_flag_get(object) & RT_OBJECT_RM))
		return (rt_true);
	return (rt_false);
}

t_rt_bool		 gui_scene_common_func_b(int rm_mod, t_object_type type)
{
	t_object	temp;

	temp.type = type;
	if (!rm_mod && (object_flag_get(&temp) & RT_OBJECT_RT))
		return (rt_true);
	if (rm_mod && (object_flag_get(&temp) & RT_OBJECT_RM))
		return (rt_true);
	return (rt_false);
}

void				gui_scene_common_func_c(GtkListStore *list, t_object *object)
{
	GtkTreeIter		iter;

	gtk_list_store_append(list, &iter);
	gtk_list_store_set(list, &iter,
		gui_objects_column_id, object->id,
		gui_objects_column_name, object->name, -1);
}