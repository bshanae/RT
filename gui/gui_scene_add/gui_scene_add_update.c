#include "gui_scene_add.h"

void 				gui_scene_add_update(t_gui_scene_add *add)
{
	GtkTreeIter		list_iter;
	int 			type_iter;

	type_iter = 0;
	while (type_iter < object_end)
	{
		gtk_list_store_append(add->type_list, &list_iter);
		gtk_list_store_set(add->type_list, &list_iter,
			scene_add_type_id, type_iter,
			scene_add_type_name, object_translate(type_iter),
			-1);
		type_iter++;
	}
}