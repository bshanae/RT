/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_julia.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 13:10:46 by ashari            #+#    #+#             */
/*   Updated: 2019/10/01 18:09:14 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object_interaction.h"

void				object_julia_build(t_object *space, va_list *args)
{
	t_object_julia	*data;

	data = (t_object_julia *)space->data;
	data->position = va_arg(*args, RT_F4_API);
	data->iterations = va_arg(*args, int);
	data->value = va_arg(*args, RT_F4_API);
	space->type = object_type_julia;
}
