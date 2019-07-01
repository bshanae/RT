/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 14:03:01 by bshanae           #+#    #+#             */
/*   Updated: 2019/05/23 14:04:10 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_ft_printf.h"

void				long_add(t_long *me, u_int n)
{
	int				i;

	i = 0;
	while (n)
	{
		if (i >= me->length)
			long_push_back(me, 0);
		n += *long_at(me, i);
		*long_at(me, i) = n % 10;
		n /= 10;
		i++;
	}
}

void				long_add_long(t_long *me, t_long *other)
{
	int				i;
	int				temp;

	i = 0;
	temp = 0;
	while (i < me->length || i < other->length || temp)
	{
		if (i >= me->length)
			long_push_back(me, 0);
		if (i < other->length)
			temp += *long_at(other, i);
		temp += *long_at(me, i);
		*long_at(me, i) = temp % 10;
		temp /= 10;
		i++;
	}
}

void				long_multiply(t_long *me, u_int n)
{
	int				i;
	u_int			temp;

	i = 0;
	temp = 0;
	while (i < me->length || temp)
	{
		if (i >= me->length)
			long_push_back(me, 0);
		temp += *long_at(me, i) * n;
		*long_at(me, i) = temp % 10;
		temp /= 10;
		i++;
	}
}

void				long_print(t_long *me)
{
	int				i;
	char			c;

	i = me->length - 1;
	while (i != -1)
	{
		c = '0' + *long_at(me, i--);
		write(1, &c, 1);
	}
	write(1, "\n", 1);
}
