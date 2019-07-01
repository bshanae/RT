/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_pop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 20:21:08 by bshanae           #+#    #+#             */
/*   Updated: 2019/06/05 20:23:33 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_queue.h"

void						queue_pop(t_queue *me)
{
	t_queue_piece *temp;

	if (!me || me->length < 1)
		return ;
	temp = me->begin;
	me->begin = me->begin->next;
	free(temp->data);
	free(temp);
	if (!(--me->length))
		me->end = NULL;
}
