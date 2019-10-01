/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_limited.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 13:11:00 by ashari            #+#    #+#             */
/*   Updated: 2019/10/01 18:09:14 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object_interaction.h"

void					object_limited_build(t_object *space, va_list *args)
{
	t_object_limited	*limited;

	limited = (t_object_limited *)space->data;
	limited->main_id = -1;
	limited->limit_id = -1;
	ft_strcpy(limited->main_name, va_arg(*args, const char *));
	ft_strcpy(limited->limit_name, va_arg(*args, const char *));
	space->type = object_type_limited;
}
