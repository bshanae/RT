#include "scene.h"

void 				scene_remove_object(t_scene *scene, int object_id)
{
	int 			i;

	i = object_id;
	while (i < scene->objects_length - 1)
	{
		scene->objects[i] = scene->objects[i + 1];
		i++;
	}
	scene->objects_length--;
	scene_update(scene);
}