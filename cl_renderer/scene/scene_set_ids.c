#include "scene.h"

void 				scene_set_ids(t_scene *scene)
{
	int 			i;

	i = 0;
	while (i < RT_CL_SCENE_CAPACITY)
	{
		scene->objects[i].id = i;
		i++;
	}
}
