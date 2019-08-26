#include "scene.h"

void 				scene_update(t_scene *scene)
{
	int 			i;
	int 			j;

	i = 0;
	while (i < RT_CL_SCENE_CAPACITY)
	{
		scene->objects[i].id = i;
		i++;
	}
	i = 0;
	j = 0;
	while (i < scene->objects_length)
	{
		if (scene->objects[i].type == object_light_ambient ||
			scene->objects[i].type == object_light_point ||
			scene->objects[i].type == object_light_direct)
			scene->lights[j++] = scene->objects[i].id;
		if (scene->objects[i].type == object_csg)
		{
			scene->objects[((t_object_csg *)scene->objects[i].data)->id_positive].is_csg = 1;
			scene->objects[((t_object_csg *)scene->objects[i].data)->id_negative].is_csg = 1;
		}
		i++;
	}
	scene->lights_length = j;
}
