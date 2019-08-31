#include "scene.h"
#include "material_list.h"

static void			set_args
					(t_object *object, int texture_id, t_scene_texture_flag flag)
{
	object->texture_id = texture_id;
	object->material = MATERIAL_WHITE;
}

void				scene_texture_set
					(t_scene *scene, int texture_id, t_scene_texture_flag flag, ...)
{
	static int 		i;
	va_list 		args;
	int 			id;

	if (flag == scene_texture_next)
		set_args(&scene->objects[i], texture_id, flag);
	else if (flag == scene_texture_last)
		set_args(&scene->objects[scene->objects_length - 1], texture_id, flag);
	else if (flag == scene_texture_id)
	{
		va_start(args, flag);
		id = va_arg(args, int);
		set_args(&scene->objects[id], texture_id, flag);
		va_end(args);
	}
}
