#include "gui_scene_add.h"

GtkBox				*gui_scene_add_get_object(t_gui_scene_add *add)
{
	if (add->current_type == object_sphere)
		return (add->sphere.box);
	else if (add->current_type == object_plane)
		return (add->plane.box);
	return (NULL);
}