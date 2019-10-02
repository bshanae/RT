/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_func_x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 15:22:31 by ashari            #+#    #+#             */
/*   Updated: 2019/10/01 18:09:14 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

void				scene_func_a(t_scene *scene, int i)
{
	t_object_pair		*pair;
	t_object			*temp[2];

	if (!(object_flag_get(scene->objects + i) & RT_OBJECT_PAIR))
		return ;
	pair = (t_object_pair *)scene->objects[i].data;
	pair->first_id = -1;
	pair->second_id = -1;
	temp[0] = scene_find_object_by_name(scene, pair->first_name);
	temp[1] = scene_find_object_by_name(scene, pair->second_name);
	if (temp[0])
		pair->first_id = temp[0]->id;
	if (temp[0] && temp[1] && temp[0]->id != -1 && temp[0]->id == temp[1]->id)
		return ;
	if (temp[1])
		pair->second_id = temp[1]->id;
}
