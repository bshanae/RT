/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_insert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 16:12:31 by bshanae           #+#    #+#             */
/*   Updated: 2019/05/14 16:12:32 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_vector.h"

void						vector_insert
	(t_vector *me, size_t i_dest, void *data)
{
	size_t					i_iter;

	if (!me->storage || !data || i_dest > me->length)
		return ;
	if ((double)(me->length + 1) / (me->capacity) >= VECTOR_ALLOC_LIMIT)
		vector_resize(me, me->capacity * VECTOR_ALLOC_MULT);
	i_iter = me->length;
	while (i_iter > 0 && i_iter != i_dest)
	{
		ft_memcpy(me->storage + i_iter * me->element_size,
			me->storage + (i_iter - 1) * me->element_size,
			me->element_size);
		i_iter--;
	}
	ft_memcpy(me->storage + i_dest * me->element_size, data, me->element_size);
	me->length++;
}
