/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_cylinder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 13:10:34 by ashari            #+#    #+#             */
/*   Updated: 2019/10/01 18:09:14 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object_interaction.h"

void					object_cylinder_build(t_object *space, va_list *args)
{
	t_object_cylinder	*data;

	data = (t_object_cylinder *)space->data;
	data->top = va_arg(*args, RT_F4_API);
	data->bottom = va_arg(*args, RT_F4_API);
	data->radius = (RT_F)va_arg(*args, double);
	data->axis = f4_normalize(f4_sub(data->top, data->bottom));
	space->type = object_type_cylinder;
	data->length_line = f4_length(f4_sub(data->top, data->bottom));
	data->length = data->length_line + data->radius * 2;
}
