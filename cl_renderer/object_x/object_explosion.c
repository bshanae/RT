/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_explosion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 13:10:40 by ashari            #+#    #+#             */
/*   Updated: 2019/10/01 18:09:14 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object_interaction.h"

void					object_explosion_build(t_object *space, va_list *args)
{
	t_object_explosion	*data;

	data = (t_object_explosion *)space->data;
	data->position = va_arg(*args, RT_F4_API);
	data->radius = (RT_F)va_arg(*args, double);
	data->noise_amplitude = (RT_F)va_arg(*args, double);
	space->type = object_type_explosion;
}
