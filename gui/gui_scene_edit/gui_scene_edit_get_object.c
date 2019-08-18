#include "gui_scene_edit.h"

GtkBox				*gui_scene_edit_get_object
					(t_gui_scene_edit *edit, t_object_type type)
{
	if (type == object_sphere)
		return (edit->sphere.box);
	else if (type == object_plane)
		return (edit->plane.box);
	return (NULL);
}