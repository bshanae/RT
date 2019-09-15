#include "gui_scene_common.h"

void				gui_scene_common_add_to_list
					(GtkListStore *list, t_object *object)
{
	GtkTreeIter		iter;

	gtk_list_store_append(list, &iter);
	gtk_list_store_set(list, &iter,
		gui_objects_column_id, object->id,
		gui_objects_column_name, object->name, -1);
}