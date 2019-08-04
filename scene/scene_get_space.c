#include "scene.h"

void				*scene_get_space(t_scene *scene, int purpose)
{
	if (purpose == SCENE_SPACE_OBJECT &&
		scene->objects_length < SCENE_OBJECTS_CAPACITY)
		return (scene->objects + scene->objects_length++);
	if (purpose == SCENE_SPACE_LIGHT &&
		scene->lights_length < SCENE_LIGHTS_CAPACITY)
		return (scene->lights + scene->lights_length++);
	return (NULL);
}