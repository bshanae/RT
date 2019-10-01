/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_moebius.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 13:11:14 by ashari            #+#    #+#             */
/*   Updated: 2019/10/01 18:09:14 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object_interaction.h"

void					object_moebius_build(t_object *space, va_list *args)
{
	t_object_moebius	*data;

	data = (t_object_moebius *)space->data;
	data->position = va_arg(*args, RT_F4_API);
	data->radius = (RT_F)va_arg(*args, double);
	data->half_width = data->radius / (RT_F)2.;
	space->type = object_type_moebius;
}
