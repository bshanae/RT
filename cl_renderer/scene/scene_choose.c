#include "scene.h"

void				scene_choose(t_scene *scene, int id)
{
	int 			i;

	i = 0;
	while (i < scene->objects_length)
		scene->objects[i++].is_chosen = 0;
	if (id != -1)
		scene->objects[id].is_chosen = 1;
}