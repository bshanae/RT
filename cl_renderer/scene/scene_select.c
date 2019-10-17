/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_un_select.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 15:23:15 by ashari            #+#    #+#             */
/*   Updated: 2019/10/17 13:59:27 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

void				scene_select(t_scene *scene, int id)
{
	scene_unselect(scene);
	if (id == -1)
		return ;
	if (!scene_find_object_by_id(scene, id))
		return ;
	scene->objects[id].is_selected = rt_true;
	scene->selected_id = id;
}

void				scene_unselect(t_scene *scene)
{
	int				i;

	i = 0;
	while (i < scene->objects_length)
		scene->objects[i++].is_selected = rt_false;
	scene->selected_id = -1;
}
