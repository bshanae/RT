#include "scene.h"

void 				scene_clear(t_scene *scene)
{
	scene->objects_length = 0;
	scene->lights_length = 0;
}