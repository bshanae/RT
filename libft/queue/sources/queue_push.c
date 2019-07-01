/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 20:20:48 by bshanae           #+#    #+#             */
/*   Updated: 2019/06/05 20:22:46 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_queue.h"

void						queue_push(t_queue *me, void *data)
{
	t_queue_piece			*new;

	if (!me || !data || me->length == -1)
		return ;
	new = (t_queue_piece *)malloc(sizeof(t_queue_piece));
	if (!(new->data = malloc(me->data_size)))
		exit(1);
	new->next = NULL;
	ft_memcpy(new->data, data, me->data_size);
	if (!me->end)
	{
		me->begin = new;
		me->end = new;
	}
	else
	{
		me->end->next = new;
		me->end = new;
	}
	me->length++;
}
