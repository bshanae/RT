/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape_cone.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <ashari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 19:13:04 by ashari            #+#    #+#             */
/*   Updated: 2019/06/30 19:13:05 by ashari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shape_list.h"

void				cone_move(t_shape *shape, t_vector3 move)
{
	t_cone_data		*data;

	data = (t_cone_data *)shape->data;
	vector3_add_eq(&data->top, &move);
	vector3_add_eq(&data->bottom, &move);
}

t_shape				shape_cone
	(t_vector3 top, t_vector3 bottom, float tangens, t_material material)
{
	t_shape			shape;
	t_cone_data		*data;

	shape.id = SHAPE_ID_CONE;
	data = (t_cone_data *)shape.data;
	data->top = top;
	data->bottom = bottom;
	data->axis = vector3_sub(&bottom, &top);
	data->tangens = tan(tangens * M_PI / 180);
	data->radius = data->tangens * vector3_s_length(data->axis);
	data->axis = vector3_s_normalize(data->axis);
	shape.material = material;
	shape.highlight = 0;
	return (shape);
}
