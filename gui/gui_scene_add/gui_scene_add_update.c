#include "gui_scene_add.h"

void 				gui_scene_add_load_types(t_gui_scene_add *add)
{
	GtkTreeIter		iter_list;
	int 			iter_type;

	iter_type = 0;
	while (iter_type < object_type_end)
	{
		gtk_list_store_append(add->type_list, &iter_list);
		gtk_list_store_set(add->type_list, &iter_list,
			scene_add_type_id, iter_type,
			scene_add_type_name, object_translate(iter_type),
			-1);
		iter_type++;
	}
}