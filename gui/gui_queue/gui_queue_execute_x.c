/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_queue_execute_x.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 15:49:09 by bshanae           #+#    #+#             */
/*   Updated: 2019/10/17 13:59:27 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_queue.h"

void				gui_queue_execute(void *ptr, t_gui_queue *queue)
{
	int				force;

	force = queue->force_execute;
	if (force)
		queue->force_execute = 0;
	if (!force && queue->block)
		return ;
	if (!force && queue->pass)
	{
		queue->pass--;
		return ;
	}
	if (!force && g_thread_pool_unprocessed(queue->pool) > RT_GUI_QUEUE_CEILING)
		return ;
	queue->free = 0;
	queue->master_function(queue->master_data);
	if (force)
		queue->force_finished = 1;
	queue->free = 1;
}

#ifdef RT_QUEUE_MANUAL

void				gui_queue_execute_force(t_gui_queue *queue)
{
	queue->master_function(queue->master_data);
}

#elif defined RT_QUEUE_AUTO

void				gui_queue_execute_force(t_gui_queue *queue)
{
	gui_queue_push(queue);
	queue->force_execute = 1;
	queue->force_finished = 0;
	queue->pass = RT_GUI_QUEUE_PASS;
}

#endif
