#include "gui_scene_edit.h"

void				gui_scene_edit_gen_name(t_object *object, int reset_flag)
{
	int 			i;
	static int 		id[object_end];
	char			*temp;

	if (reset_flag)
	{
		i = 0;
		while (i < object_end)
			id[i++] = 0;
		return ;
	}
	ft_strcpy(object->name, object_translate(object->type));
	temp = ft_itoa(id[object->type]++);
	ft_strcat(object->name, " no. ");
	ft_strcat(object->name, temp);
	free(temp);
}