/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <ashari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 19:10:54 by ashari            #+#    #+#             */
/*   Updated: 2019/07/01 12:05:47 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light.h"

t_light				light_create(t_light_type type, ...)
{
	t_light			new;
	va_list			args;

	new.type = type;
	va_start(args, type);
	new.intensity = (float)va_arg(args, double);
	if (type == light_point || type == light_directional)
		new.vector = va_arg(args, t_vector3);
	va_end(args);
	return (new);
}

void				light_move(t_light *light, t_vector3 step)
{
	vector3_add_eq(&light->vector, &step);
}
