#include "scene.h"

void					static_set_id(t_scene *scene)
{
	int 				i;

	i = 0;
	while (i < RT_CL_SCENE_CAPACITY)
	{
		scene->objects[i].id = i;
		i++;
	}
}

void					static_set_lights(t_scene *scene)
{
	int 				i;
	int 				j;

	i = 0;
	j = 0;
	while (i < scene->objects_length)
	{
		if (scene->objects[i].type == object_type_light_ambient ||
			scene->objects[i].type == object_type_light_point ||
			scene->objects[i].type == object_type_light_direct)
			scene->lights[j++] = scene->objects[i].id;
		i++;
	}
	scene->lights_length = j;
}

void					static_set_visibilty(t_scene *scene)
{
	int 				i;
	t_object_csg		*csg;
	t_object_limited	*limited;

	i = 0;
	while (i < scene->objects_length)
	{
		if (scene->objects[i].type == object_type_csg)
		{
			csg = ((t_object_csg *)scene->objects[i].data);
			scene->objects[csg->id_positive].is_visible = 0;
			scene->objects[csg->id_negative].is_visible = 0;
		}
		else if (scene->objects[i].type == object_type_limited)
		{
			limited = ((t_object_limited *)scene->objects[i].data);
			scene->objects[limited->id_main].is_visible = 0;
			scene->objects[limited->id_limit].is_visible = 0;
		}
		else
			scene->objects[i].is_visible = 1;
		i++;
	}
}

void 				scene_update(t_scene *scene)
{
	static_set_id(scene);
	static_set_lights(scene);
	static_set_visibilty(scene);
}
