/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <ashari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 19:13:08 by ashari            #+#    #+#             */
/*   Updated: 2019/07/01 12:05:47 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shape_list.h"

void				cylinder_move(t_shape *shape, t_vector3 move)
{
	t_cylinder_data	*data;

	data = (t_cylinder_data *)shape->data;
	vector3_add_eq(&data->top, &move);
	vector3_add_eq(&data->bottom, &move);
}

t_shape				shape_cylinder
	(t_vector3 top, t_vector3 bottom, float radius, t_material material)
{
	t_shape			shape;
	t_cylinder_data	*data;

	shape.id = SHAPE_ID_CYLINDER;
	data = (t_cylinder_data *)shape.data;
	data->top = top;
	data->bottom = bottom;
	data->radius = radius;
	data->axis = vector3_s_normalize(vector3_sub(&top, &bottom));
	shape.material = material;
	shape.highlight = 0;
	return (shape);
}
