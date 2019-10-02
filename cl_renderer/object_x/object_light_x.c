/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_light_x.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 13:10:53 by ashari            #+#    #+#             */
/*   Updated: 2019/10/01 18:09:14 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object_interaction.h"

void						object_light_ambient_build(
							t_object *space, va_list *args)
{
	t_object_light_ambient	*data;

	data = (t_object_light_ambient *)space->data;
	space->type = object_type_light_ambient;
}

void						object_light_point_build(
							t_object *space, va_list *args)
{
	t_object_light_point	*data;

	data = (t_object_light_point *)space->data;
	data->position = va_arg(*args, RT_F4_API);
	space->type = object_type_light_point;
}

void						object_light_direct_build(
							t_object *space, va_list *args)
{
	t_object_light_direct	*data;

	data = (t_object_light_direct *)space->data;
	data->direction = f4_normalize(va_arg(*args, RT_F4_API));
	space->type = object_type_light_direct;
}
