/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_queue_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 15:55:22 by bshanae           #+#    #+#             */
/*   Updated: 2019/10/02 16:12:26 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_queue.h"

#ifdef RT_QUEUE_AUTO

gboolean			gui_queue_push(t_gui_queue *queue)
{
	if (queue->kill_timeout)
		return (FALSE);
	g_thread_pool_push(queue->pool, queue, NULL);
	return (TRUE);
	return (FALSE);
}

#else

gboolean			gui_queue_push(t_gui_queue *queue)
{
	return (FALSE);
}

#endif
