/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_edit_param.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 15:22:17 by ashari            #+#    #+#             */
/*   Updated: 2019/10/01 18:09:14 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

void				scene_edit_param(t_scene *scene, int id, ...)
{
	t_scene_param	param;
	va_list			args;
	CHAR_REF		str;
	t_material		material;

	if (id == -1)
		id = scene->objects_length - 1;
	va_start(args, id);
	param = va_arg(args, t_scene_param);
	if (param == scene_param_name)
	{
		str = va_arg(args, char *);
		ft_strcpy(scene->objects[id].name, str);
	}
	else if (param == scene_param_material)
	{
		material = va_arg(args, t_material);
		scene->objects[id].material = material;
	}
	else if (param == scene_param_texture)
	{
		str = va_arg(args, CHAR_REF);
		scene->objects[id].texture_id =
			scene_find_texture_by_name(scene, str);
	}
}
