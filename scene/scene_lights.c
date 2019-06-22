#include "scene.h"

void				scene_light_push(t_scene *me, t_light *light)
{
	vector_push_back(&me->lights, &light);
}

t_light				*scene_light_at(t_scene *me, int i)
{
	return (*(t_light **)vector_at(&me->lights, i));
}