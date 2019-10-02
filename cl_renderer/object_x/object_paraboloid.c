/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_paraboloid.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 13:11:29 by ashari            #+#    #+#             */
/*   Updated: 2019/10/01 18:09:14 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object_interaction.h"

void					object_paraboloid_build(
						t_object *space, va_list *args)
{
	t_object_paraboloid	*data;

	data = (t_object_paraboloid *)space->data;
	data->extremum = va_arg(*args, RT_F4_API);
	data->axis = f4_normalize(va_arg(*args, RT_F4_API));
	data->radius = (RT_F)va_arg(*args, double);
	space->type = object_type_paraboloid;
}
