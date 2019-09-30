/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_destroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 20:21:33 by bshanae           #+#    #+#             */
/*   Updated: 2019/06/05 20:23:33 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_queue.h"

void						queue_destroy(t_queue *me)
{
	if (!me || me->length < 1)
		return ;
	while (me->length > 0)
		queue_pop(me);
}
