/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 20:25:22 by bshanae           #+#    #+#             */
/*   Updated: 2019/06/05 20:25:22 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_queue.h"

void						queue_print(t_queue *me, void (*f)(void *))
{
	t_queue_piece			**iter;

	iter = &me->begin;
	if (!*iter)
		ft_printf("queue is empty\n");
	while (*iter)
	{
		ft_printf("[");
		f((*iter)->data);
		ft_printf("]");
		iter = &(*iter)->next;
		if (*iter)
			ft_printf("->");
		else
			ft_printf("\n");
	}
}
