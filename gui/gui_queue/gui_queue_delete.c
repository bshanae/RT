/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_queue_delete.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 15:48:42 by bshanae           #+#    #+#             */
/*   Updated: 2019/10/02 15:48:43 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_queue.h"

void				gui_queue_delete(t_gui_queue **queue)
{
	g_thread_pool_free((*queue)->pool, TRUE, TRUE);
	free(*queue);
	*queue = NULL;
}
