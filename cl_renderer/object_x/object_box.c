/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_box.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 13:10:16 by ashari            #+#    #+#             */
/*   Updated: 2019/10/01 18:09:14 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object_interaction.h"

void				object_box_build(t_object *space, va_list *args)
{
	t_object_box	*data;

	data = (t_object_box *)space->data;
	data->position = va_arg(*args, RT_F4_API);
	data->size = va_arg(*args, RT_F4_API);
	space->type = object_type_box;
}
