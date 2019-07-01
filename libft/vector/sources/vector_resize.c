/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_enlarge.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 16:09:23 by bshanae           #+#    #+#             */
/*   Updated: 2019/05/28 20:58:05 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_vector.h"

void						vector_resize(t_vector *me, size_t capacity)
{
	void					*new_storage;

	new_storage = malloc(capacity * me->element_size);
	if (!new_storage)
		return ;
	ft_memcpy(new_storage, me->storage, me->length * me->element_size);
	free(me->storage);
	me->storage = new_storage;
	me->capacity = capacity;
}
