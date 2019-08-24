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
		i++;
	}
	scene->lights_length = j;
}
