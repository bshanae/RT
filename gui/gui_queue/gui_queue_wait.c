/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_queue_wait.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 16:13:52 by bshanae           #+#    #+#             */
/*   Updated: 2019/10/02 16:13:53 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_queue.h"

void				gui_queue_wait(t_gui_queue *queue)
{
	double			start;
	double			current;

	start = gui_queue_get_time();
	while (!queue->force_finished)
	{
		current = gui_queue_get_time();
		if (current - start > RT_GUI_QUEUE_WAIT_LIMIT)
			break ;
	}
}
