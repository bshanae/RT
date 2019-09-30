/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_push_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 16:11:50 by bshanae           #+#    #+#             */
/*   Updated: 2019/05/14 16:11:51 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_vector.h"

void						*vector_push_back(t_vector *me, void *data)
{
	if (!me->storage || !data)
		return (NULL);
	if ((double)(me->length + 1) / (me->capacity) >= VECTOR_ALLOC_LIMIT)
		vector_resize(me, me->capacity * VECTOR_ALLOC_MULT);
	ft_memcpy(me->storage + me->element_size * me->length,
		data, me->element_size);
	me->length++;
	return (vector_at(me, me->length - 1));
}
