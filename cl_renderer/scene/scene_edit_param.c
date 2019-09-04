#include "scene.h"

void				scene_edit_param(t_scene *scene, int id, ...)
{
	t_scene_param	param;
	va_list 		args;
	CHAR_REF		str;
	t_material		material;

	if (id == -1)
		id = scene->objects_length - 1;
	va_start(args, id);
	while (1)
	{
		param = va_arg(args, t_scene_param);
		if (param == scene_param_name)
		{
			str = va_arg(args, char *);
			ft_strcpy(scene->objects[id].name, str);
		}
		else if (param == scene_param_material)
		{
			material = va_arg(args, t_material);
			scene->objects[id].material = material;
		}
		else if (param == scene_param_end)
			break ;
	}
}