#include "scene.h"

void				scene_shape_push(t_scene *me, t_shape *shape)
{
	vector_push_back(&me->shapes, &shape);
}

t_shape				*scene_shape_at(t_scene *me, int i)
{
	return (*(t_shape **)vector_at(&me->shapes, i));
}
