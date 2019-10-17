/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_torus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 13:12:01 by ashari            #+#    #+#             */
/*   Updated: 2019/10/17 13:59:27 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object_interaction.h"

void						object_torus_build(t_object *space, va_list *args)
{
	t_object_torus			*data;

	data = (t_object_torus *)space->data;
	data->position = va_arg(*args, RT_F4_API);
	data->radius = (RT_F)va_arg(*args, double);
	data->width = (RT_F)va_arg(*args, double);
	space->type = object_type_torus;
}
