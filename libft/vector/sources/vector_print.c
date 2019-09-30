/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 21:06:57 by bshanae           #+#    #+#             */
/*   Updated: 2019/05/28 21:07:04 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_vector.h"

void						vector_print(t_vector *me, void (*f)(const void *))
{
	u_long					i;

	write(1, "{", 1);
	i = 0;
	while (i < me->length)
	{
		f(me->storage + i++ * me->element_size);
		if (i < me->length)
			write(1, ", ", 2);
	}
	write(1, "}\n", 2);
}
