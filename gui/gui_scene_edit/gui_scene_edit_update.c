#include "gui_scene_edit.h"

void 				gui_scene_edit_update
					(t_gui_scene_edit *edit, t_scene *scene)
{
	int 			i;
	GtkTreeIter		iter;

	i = 0;
	gtk_list_store_clear(edit->list);
	while (i < scene->objects_length)
	{
		if (!scene->objects[i].name[0])
			gui_scene_edit_gen_name(scene->objects + i);
		gtk_list_store_append(edit->list, &iter);
		gtk_list_store_set(
			edit->list, &iter,
			scene_edit_object_id, scene->objects[i].id,
			scene_edit_object_name, scene->objects[i].name,
			// todo add icon
			scene_edit_type_id, scene->objects[i].type,
			-1);
		i++;
	}
}