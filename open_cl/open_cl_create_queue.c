/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_cl_create_queue.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <ashari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 19:11:41 by ashari            #+#    #+#             */
/*   Updated: 2019/06/30 19:11:42 by ashari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "open_cl.h"

void				open_cl_create_queue(t_open_cl *me)
{
	int				error;

	me->queue = clCreateCommandQueue(me->context, me->device_id, 0, &error);
	error_check(__LINE__, __FUNCTION__, error);
}
