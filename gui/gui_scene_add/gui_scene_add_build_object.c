#include "gui_scene_add.h"

void				gui_scene_add_build_object
					(t_gui_scene_add *add, t_object *space)
{
	if (add->current_type == object_end)
		return ; // todo add warning
	else if (add->current_type == object_sphere)
		gui_object_sphere_build(&add->sphere, space);
	else if (add->current_type == object_plane)
		gui_object_plane_build(&add->plane, space);
}