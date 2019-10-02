/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_queue_start.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 16:13:41 by bshanae           #+#    #+#             */
/*   Updated: 2019/10/02 16:13:41 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_queue.h"

void				gui_queue_start(t_gui_queue *queue)
{
	g_timeout_add(RT_GUI_QUEUE_FREQUENCY, (GSourceFunc)gui_queue_push, queue);
}
