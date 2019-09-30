/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_pop_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 16:10:25 by bshanae           #+#    #+#             */
/*   Updated: 2019/05/28 20:41:30 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_vector.h"

void						vector_pop_back(t_vector *me)
{
	if (!me->storage || !me->length)
		return ;
	ft_memset(me->storage + me->element_size * (me->length - 1),
		0, me->element_size);
	me->length--;
}
