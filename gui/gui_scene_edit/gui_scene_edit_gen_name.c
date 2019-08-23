#include "gui_scene_edit.h"

void				gui_scene_edit_gen_name(t_object *object)
{
	static int 		id[object_end];
	char			*temp;

	ft_strcpy(object->name, object_translate(object->type));
	temp = ft_itoa(id[object->type]++);
	ft_strcat(object->name, " No. ");
	ft_strcat(object->name, temp);
	free(temp);
}