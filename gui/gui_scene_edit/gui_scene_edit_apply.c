#include "gui_scene_edit.h"

void 				gui_scene_edit_apply
					(t_gui_scene_edit *edit, t_object* object)
{
	ft_strcpy(object->name, gui_entry_get_str(edit->name));
	gtk_list_store_set(edit->list, &edit->iter,
		scene_edit_object_name, object->name, -1);
	if (object->type == object_sphere)
		gui_object_sphere_build(&edit->sphere, object);
	else if (object->type == object_plane)
		gui_object_plane_build(&edit->plane, object);
	else if (object->type == object_cone)
		gui_object_cone_build(&edit->cone, object);
	else if (object->type == object_cylinder)
		gui_object_cylinder_build(&edit->cylinder, object);
	gui_material_build(&edit->material, &object->material);
	gui_material_show(&edit->material, &object->material);
}