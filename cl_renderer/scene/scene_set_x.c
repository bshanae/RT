#include "scene.h"

void					scene_set_id(t_scene *scene)
{
	int 				i;

	i = 0;
	while (i < RT_CL_SCENE_CAPACITY)
	{
		scene->objects[i].id = i;
		i++;
	}
}

void					scene_set_pair(t_scene *scene)
{
	int 				i;
	t_object_pair		*pair;
	t_object			*temp;

	i = 0;
	while (i < scene->objects_length)
		scene->objects[i++].is_visible = 1;
	i = 0;
	while (i < scene->objects_length)
	{
		if (object_flag_get(scene->objects + i) & RT_OBJECT_PAIR)
		{
			pair = (t_object_pair *)scene->objects[i].data;
			pair->first_id = -1;
			pair->second_id = -1;
			if ((temp = scene_find_by_name(scene, pair->first_name)))
				pair->first_id = temp->id;
			if ((temp = scene_find_by_name(scene, pair->second_name)))
				pair->second_id = temp->id;
		}
		i++;
	}
}

void					scene_set_light(t_scene *scene)
{
	int 				i;
	int 				j;

	i = 0;
	j = 0;
	while (i < scene->objects_length)
	{
		if (object_flag_get(scene->objects + i) & RT_OBJECT_LIGHT)
			scene->lights[j++] = scene->objects[i].id;
		i++;
	}
	scene->lights_length = j;
}

void					scene_set_visibility(t_scene *scene)
{
	int 				i;
	t_object_pair		*pair;
	t_object			*temp;

	i = 0;
	while (i < scene->objects_length)
		scene->objects[i++].is_visible = 1;
	i = 0;
	while (i < scene->objects_length)
	{
		if (object_flag_get(scene->objects + i) & RT_OBJECT_PAIR)
		{
			pair = (t_object_pair *)scene->objects[i].data;
			if ((temp = scene_find_by_id(scene, pair->first_id)))
				temp->is_visible = 0;
			if ((temp = scene_find_by_id(scene, pair->second_id)))
				temp->is_visible = 0;
			scene->objects[i].is_visible = 0;
		}
		i++;
	}
}
