/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 21:06:57 by bshanae           #+#    #+#             */
/*   Updated: 2019/05/28 21:19:09 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_vector.h"

void						*vector_find
	(t_vector *me, const void *ptr, int (*cmp)(const void *, const void *))
{
	u_long					i;

	i = 0;
	while (i < me->length)
	{
		if (!cmp(me->storage + i * me->element_size, ptr))
			return (me->storage + i * me->element_size);
		i++;
	}
	return (NULL);
}
