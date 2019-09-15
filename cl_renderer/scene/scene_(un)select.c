#include "scene.h"

void				scene_select(t_scene *scene, int id)
{
	int 			i;

	i = 0;
	while (i < scene->objects_length)
		scene->objects[i++].is_selected = rt_false;
	if (id != -1)
		scene->objects[id].is_selected = rt_true;
}

void				scene_unselect(t_scene *scene)
{
	int 			i;

	i = 0;
	while (i < scene->objects_length)
		scene->objects[i++].is_selected = rt_false;
}