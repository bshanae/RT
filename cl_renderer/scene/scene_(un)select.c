#include "scene.h"

void				scene_select(t_scene *scene, int id)
{
	int 			i;

	i = 0;
	while (i < scene->objects_length)
		scene->objects[i++].is_selected = 0;
	if (id != -1)
		scene->objects[id].is_selected = 1;
}

void				scene_unselect(t_scene *scene)
{
	int 			i;

	i = 0;
	while (i < scene->objects_length)
		scene->objects[i++].is_selected = 0;
}