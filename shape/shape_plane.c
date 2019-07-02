/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <ashari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 19:13:16 by ashari            #+#    #+#             */
/*   Updated: 2019/07/02 19:23:23 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shape_list.h"

int 			plane_intersect
	(t_shape *shape, t_intersection *intersection)
{
	t_plane_data	*data;
	t_vector3		temp[2];
	float 			value[3];

	data = (t_plane_data *)shape->data;
	if (!(value[0] = vector3_dot(&intersection->ray.direction, &data->normal)))
		return (0);
	temp[0] = vector3_sub(&data->position, &intersection->ray.origin);
	value[1] = vector3_dot(temp, &data->normal) / value[0];
	if (value[1] <= RAY_T_MIN || value[1] >= intersection->ray.t)
		return (0);
	intersection->ray.t = value[1];
	intersection->normal = data->normal;
	intersection->color = shape->material.color;
	intersection->material = shape->material;
	return (1);
}

void				plane_move(t_shape *shape, t_vector3 move)
{
	t_plane_data	*data;

	data = (t_plane_data *)shape->data;
	vector3_add_eq(&data->position, &move);
}

t_shape				shape_plane
	(t_vector3 position, t_vector3 normal, t_material material)
{
	t_shape			shape;
	t_plane_data	*data;

	shape.id = SHAPE_ID_PLANE;
	data = (t_plane_data *)shape.data;
	data->position = position;
	data->normal = vector3_normalized(&normal);
	shape.material = material;
	return (shape);
}
