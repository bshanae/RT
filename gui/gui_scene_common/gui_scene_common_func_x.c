#include "gui_scene_common.h"

t_rt_bool		gui_scene_common_func_a(int rm_mod, t_object *object)
{
	if (!rm_mod && (object_flag_get(object) & RT_OBJECT_RT))
		return (rt_true);
	if (rm_mod && (object_flag_get(object) & RT_OBJECT_RM))
		return (rt_true);
	return (rt_false);
}

void				gui_scene_common_func_b(GtkListStore *list, t_object *object)
{
	GtkTreeIter		iter;

	gtk_list_store_append(list, &iter);
	gtk_list_store_set(list, &iter,
		gui_scene_column_id, object->id,
		gui_scene_column_name, object->name, -1);
}