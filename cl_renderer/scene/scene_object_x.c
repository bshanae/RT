/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_object_x.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 15:22:54 by ashari            #+#    #+#             */
/*   Updated: 2019/10/01 18:09:14 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

void				scene_object_remove(t_scene *scene, int object_id)
{
	int				i;
	t_object_pair	*pair;

	i = 0;
	while (i < scene->objects_length)
	{
		if (object_flag_get(scene->objects + i) & RT_OBJECT_PAIR)
		{
			pair = (t_object_pair *)scene->objects[i].data;
			if (!ft_strcmp(scene->objects[object_id].name, pair->first_name))
				ft_bzero(pair->first_name, RT_NAME_SIZE);
			if (!ft_strcmp(scene->objects[object_id].name, pair->second_name))
				ft_bzero(pair->second_name, RT_NAME_SIZE);
		}
		i++;
	}
	i = object_id;
	while (i < scene->objects_length - 1)
	{
		scene->objects[i] = scene->objects[i + 1];
		i++;
	}
	scene->objects_length--;
	scene_update(scene);
}

void				scene_object_rename(
					t_scene *scene, int object_id, CHAR_REF name)
{
	int				i;
	t_object_pair	*pair;

	i = 0;
	while (i < scene->objects_length)
	{
		if (object_flag_get(scene->objects + i) & RT_OBJECT_PAIR)
		{
			pair = (t_object_pair *)scene->objects[i].data;
			if (!ft_strcmp(name, pair->first_name))
				ft_strcpy(pair->first_name, name);
			else if (!ft_strcmp(name, pair->second_name))
				ft_strcpy(pair->second_name, name);
		}
		i++;
	}
	ft_strcpy(scene->objects[object_id].name, name);
}
