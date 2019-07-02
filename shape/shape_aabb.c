/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape_aabb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <ashari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 19:12:58 by ashari            #+#    #+#             */
/*   Updated: 2019/07/02 20:11:24 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shape_list.h"

void				aabb_move(t_shape *shape, t_vector3 move)
{
	t_aabb_data		*data;

	data = (t_aabb_data *)shape->data;
	vector3_add_eq(&data->min, &move);
	vector3_add_eq(&data->max, &move);
}

t_shape				shape_aabb
	(t_vector3 min, t_vector3 max, t_material material)
{
	t_shape			shape;
	t_aabb_data		*data;

	shape.id = SHAPE_ID_AABB;
	data = (t_aabb_data *)shape.data;
	data->max = max;
	data->min = min;
	shape.material = material;
	return (shape);
}
