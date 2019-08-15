#include "gui_scene_add.h"

void				gui_scene_add_build_object
					(t_gui_scene_add *add, t_object *space)
{
	if (!gtk_entry_get_text(add->name)[0])
		add->gen_name_next++;
	if (add->current_type == object_sphere)
		gui_object_sphere_build(&add->sphere, space);
	else if (add->current_type == object_plane)
		gui_object_plane_build(&add->plane, space);
	gui_material_build(&add->material, &space->material);
}