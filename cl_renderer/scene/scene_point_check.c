/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_point_check.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 15:21:41 by ashari            #+#    #+#             */
/*   Updated: 2019/10/01 18:09:14 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

int					static_point_check_one(
					t_object_plane *plane, const RT_F4_API *point)
{
	RT_F			dot_value;

	dot_value = f4_dot(f4_sub(*point, plane->position), plane->normal);
	return (dot_value > 0);
}

int					scene_point_check(t_scene *scene, const RT_F4_API *point)
{
	int				i;
	t_object_plane	*plane;
	int				proceed;

	i = 0;
	while (i < scene->objects_length)
	{
		proceed = scene->objects[i].type == object_type_plane;
		plane = (t_object_plane *)scene->objects[i].data;
		if (proceed && plane->is_limiting == rt_limit_no)
			proceed = 0;
		if (proceed && !static_point_check_one(plane, point))
			return (SCENE_POINT_OUTSIDE);
		i++;
	}
	return (SCENE_POINT_INSIDE);
}
