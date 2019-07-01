/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_clear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 16:06:38 by bshanae           #+#    #+#             */
/*   Updated: 2019/05/14 16:06:40 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_vector.h"

void						vector_clear(t_vector *me)
{
	if (!me->storage || !me->length)
		return ;
	ft_memset(me->storage, 0, me->length * me->element_size);
	me->length = 0;
}
