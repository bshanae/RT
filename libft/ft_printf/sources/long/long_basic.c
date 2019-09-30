/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_basic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 14:03:42 by bshanae           #+#    #+#             */
/*   Updated: 2019/05/23 14:03:42 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_ft_printf.h"

t_long				long_create(u_int init_value)
{
	t_long			new;

	new.vector = vector_create(sizeof(u_char));
	new.length = 0;
	if (!new.vector.storage)
		new.length = -1;
	long_push_back(&new, 0);
	long_add(&new, init_value);
	return (new);
}

void				long_destroy(t_long *me)
{
	if (me->vector.capacity && me->length > 0)
		vector_destroy(&me->vector);
	me->length = 0;
}

char				*long_at(t_long *me, int index)
{
	return ((char *)vector_at(&me->vector, index));
}

void				long_push_back(t_long *me, u_char value)
{
	vector_push_back(&me->vector, (void *)(u_long)(&value));
	me->length++;
}
