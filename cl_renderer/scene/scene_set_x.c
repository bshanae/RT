/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_set_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 15:23:08 by ashari            #+#    #+#             */
/*   Updated: 2019/10/17 13:59:27 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

void					scene_set_id(t_scene *scene)
{
	int					i;

	i = 0;
	while (i < RT_SCENE_CAPACITY)
	{
		scene->objects[i].id = i;
		i++;
	}
}

void					scene_set_name(t_scene *scene)
{
	int					i[2];

	i[0] = 0;
	while (i[0] < scene->objects_length)
	{
		i[1] = 0;
		while (i[1] < scene->objects_length)
		{
			if (i[0] != i[1] && scene->objects[i[0]].name[0] &&
				!ft_strcmp(scene->objects[i[0]].name,
						scene->objects[i[1]].name))
			{
				rt_raise_warning("Scene : Identical name (name = '%s')",
						scene->objects[i[1]].name);
				ft_bzero(scene->objects[i[1]].name, RT_NAME_SIZE);
			}
			i[1]++;
		}
		i[0]++;
	}
}

void					scene_set_pair(t_scene *scene)
{
	int					i;

	i = 0;
	while (i < scene->objects_length)
		scene_func_a(scene, i++);
}

void					scene_set_light(t_scene *scene)
{
	int					i;
	int					j;

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
	int					i;
	t_object_pair		*pair;
	t_object			*temp;

	i = 0;
	while (i < scene->objects_length)
		scene->objects[i++].is_visible = rt_true;
	i = 0;
	while (i < scene->objects_length)
	{
		if (!(object_flag_get(scene->objects + i) & *scene->tracing_mod_mask))
			;
		else if (object_flag_get(scene->objects + i) & RT_OBJECT_PAIR)
		{
			pair = (t_object_pair *)scene->objects[i].data;
			if ((temp = scene_find_object_by_id(scene, pair->first_id)))
				temp->is_visible = rt_false;
			if ((temp = scene_find_object_by_id(scene, pair->second_id)))
				temp->is_visible = rt_false;
		}
		i++;
	}
}
