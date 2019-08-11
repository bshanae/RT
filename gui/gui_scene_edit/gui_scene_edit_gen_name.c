#include "gui_scene_edit.h"

static const char	*gui_scene_edit_translate_type(t_object_type type)
{
	if (type == object_sphere)
		return ("sphere_");
	else if (type == object_plane)
		return ("plane_");
	return ("unknown");
}

void				gui_scene_edit_gen_name(t_object *object)
{
	static int 		id[object_total];
	char			*temp;

	ft_strcpy(object->name, gui_scene_edit_translate_type(object->type));
	temp = ft_itoa(id[object->type]++);
	ft_strcat(object->name, temp);
	free(temp);
}