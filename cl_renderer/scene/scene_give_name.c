#include "scene.h"

void				scene_give_name
					(t_scene *scene, CHAR_REF str, t_scene_name_flag flag, ...)
{
	static int 		i;
	va_list 		args;
	int 			id;

	if (flag == scene_name_next)
		ft_strcpy(scene->objects[i++].name, str);
	else if (flag == scene_name_last)
		ft_strcpy(scene->objects[scene->objects_length - 1].name, str);
	else if (flag == scene_name_id)
	{
		va_start(args, flag);
		id = va_arg(args, int);
		ft_strcpy(scene->objects[id].name, str);
		va_end(args);
	}
	else if (flag == scene_name_reset)
		i = 0;
}