/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_at.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 16:06:26 by bshanae           #+#    #+#             */
/*   Updated: 2019/05/14 16:06:31 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_vector.h"

void						*vector_at(t_vector *me, size_t index)
{
	if (!me->storage || index >= me->capacity)
		return (NULL);
	if ((double)(index + 1) / (me->capacity) >= VECTOR_ALLOC_LIMIT)
		vector_resize(me, me->capacity * VECTOR_ALLOC_MULT);
	return (me->storage + index * me->element_size);
}
