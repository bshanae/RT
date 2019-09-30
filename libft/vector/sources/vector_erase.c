/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_delete.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 16:08:58 by bshanae           #+#    #+#             */
/*   Updated: 2019/05/14 16:08:59 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_vector.h"

void						vector_erase(t_vector *me, size_t index)
{
	if (!me->storage || index > me->length)
		return ;
	while (index != me->length)
	{
		ft_memcpy(me->storage + index * me->element_size,
			me->storage + (index + 1) * me->element_size,
			me->element_size);
		index++;
	}
	me->length--;
}
