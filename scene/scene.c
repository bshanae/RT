#include "scene.h"

t_scene				*scene_new()
{
	t_scene			*new;

	new = (t_scene *)malloc(sizeof(t_scene));
	new->shapes_length = 0;
	new->lights_length = 0;
	return (new);
}

void				scene_delete(t_scene **scene)
{
	free(*scene);
	*scene = NULL;
}

void				scene_add_shape(t_scene *scene, t_shape shape)
{
	if (scene->shapes_length < SCENE_SHAPES_CAPACITY)
		scene->shapes[scene->shapes_length++] = shape;
}

void				scene_add_light(t_scene *scene, t_light light)
{
	if (scene->lights_length < SCENE_LIGHTS_CAPACITY)
		scene->lights[scene->lights_length++] = light;
}

int					scene_intersect(t_scene *scene, t_intersection *intersection)
{
	intersection->shape_index = -1;
	intersection->ray.t = INTERSECTION_MAX;
	for (int i = 0; i < scene->shapes_length; ++i)
		if (shape_intersect(scene->shapes + i, intersection))
			intersection->shape_index = i;
	return (intersection->shape_index != -1);
}