#include "scene.h"

int					scene_intersect
					(t_scene *scene, t_intersection *intersection)
{
	int				result;

	result = 0;
	for (int i = 0; i < scene->objects_length; i++)
		result += object_intersect(scene->objects + i, intersection);
	return (result != 0);
}