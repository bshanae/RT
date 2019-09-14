#include "scene.h"

void 				scene_update(t_scene *scene)
{
	scene_set_id(scene);
	scene_set_name(scene);
	scene_set_light(scene);
	scene_set_pair(scene);
	scene_set_visibility(scene);
}
