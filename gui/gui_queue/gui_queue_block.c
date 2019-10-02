/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_queue_block.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 15:48:05 by bshanae           #+#    #+#             */
/*   Updated: 2019/10/02 15:48:26 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_queue.h"

void				gui_queue_block(t_gui_queue *queue)
{
	double			start;
	double			current;

	queue->block_last_state = queue->block;
	queue->block = 1;
	start = gui_queue_get_time();
	while (!queue->free)
	{
		current = gui_queue_get_time();
		if (current - start > RT_GUI_QUEUE_WAIT_LIMIT)
			break ;
	}
}

void				gui_queue_unblock(t_gui_queue *queue)
{
	queue->block = queue->block_last_state;
}
