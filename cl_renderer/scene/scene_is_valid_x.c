#include "scene.h"

int 					scene_is_valid_id(t_scene *scene, int id)
{
	return (id > -1 && id < scene->objects_length);
}

static int 				static_is_valid_csg(t_scene *scene, t_object *object)
{
	t_object_csg		*csg;

	csg = (t_object_csg *)object->data;
	if (!scene_is_valid_id(scene, csg->id_negative) ||
		!scene_is_valid_id(scene, csg->id_positive))
		return (0);
	if (object_get_flag(scene->objects[csg->id_negative].type) ==
		object_flag_rt_only)
		return (0);
	if (object_get_flag(scene->objects[csg->id_positive].type) ==
		object_flag_rt_only)
		return (0);
	return (1);
}

static int 				static_is_valid_limited(t_scene *scene, t_object *object)
{
	t_object_limited	*limited;

	limited = (t_object_limited *)object->data;
	if (!scene_is_valid_id(scene, limited->id_main) ||
		!scene_is_valid_id(scene, limited->id_limit))
		return (0);
	if (object_get_flag(scene->objects[limited->id_main].type) ==
		object_flag_rm_only)
		return (0);
	if (scene->objects[limited->id_limit].type != object_type_plane)
		return (0);
	return (1);
}

int						scene_is_valid_content(t_scene *scene)
{
	int 				i;
	int 				result;

	i = 0;
	result = 1;
	while (i < scene->objects_length)
	{
		if (scene->objects[i].type == object_type_csg)
			result &= static_is_valid_csg(scene, scene->objects + i);
		if (scene->objects[i].type == object_type_limited)
			result &= static_is_valid_limited(scene, scene->objects + i);
		i++;
	}
	return (result);
}