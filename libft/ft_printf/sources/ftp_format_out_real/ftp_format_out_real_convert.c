/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_format_out_real_convert.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 14:08:55 by bshanae           #+#    #+#             */
/*   Updated: 2019/05/23 14:09:02 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_ft_printf.h"

static void				convert_whole
	(t_real_params *real, u_long bit_iter, int pow_iter, int is_zero)
{
	u_long				mask;
	t_long				two;

	real->whole.data = long_create(0);
	if (real->whole.data.length == -1 || is_zero)
		return ;
	mask = ((u_long)1) << bit_iter;
	two = long_create(1);
	if (two.length == -1)
		return ;
	while (pow_iter--)
		long_multiply(&two, 2);
	while (bit_iter != 64)
	{
		if (mask & real->represent.memory.mantissa)
			long_add_long(&real->whole.data, &two);
		long_multiply(&two, 2);
		bit_iter++;
		mask <<= 1u;
	}
	long_destroy(&two);
}

static void				convert_fract
	(t_real_params *real, u_long bit_iter, int pow_iter, int is_zero)
{
	u_long				mask;
	t_long				five;

	real->fract.data = long_create(1);
	if (real->fract.data.length == -1 || is_zero)
		return ;
	mask = ((u_long)1) << bit_iter;
	if ((five = long_create(1)).length == -1)
		return ;
	while (pow_iter++)
	{
		long_multiply(&five, 5);
		long_multiply(&real->fract.data, 10);
	}
	while (1)
	{
		if (mask & real->represent.memory.mantissa)
			long_add_long(&real->fract.data, &five);
		long_multiply(&five, 5);
		long_multiply(&real->fract.data, 10);
		mask >>= 1u;
		if (!bit_iter--)
			break ;
	}
	long_destroy(&five);
}

void					ftp_format_out_real_convert(t_real_params *real)
{
	if ((!real->represent.memory.mantissa && !real->represent.memory.exponent)
		|| real->represent.real == __LDBL_MIN__)
	{
		convert_whole(real, 0, 0, 1);
		convert_fract(real, 0, 0, 1);
	}
	else if (real->extract_exponent > 63)
	{
		convert_whole(real, 0, real->extract_exponent - 63, 0);
		convert_fract(real, 0, 0, 1);
	}
	else if (real->extract_exponent < 0)
	{
		convert_whole(real, 0, 0, 1);
		convert_fract(real, 63, real->extract_exponent, 0);
	}
	else
	{
		convert_whole(real, 63 - real->extract_exponent, 0, 0);
		convert_fract(real, 62 - real->extract_exponent, -1, 0);
	}
	real->whole.length = real->whole.data.length;
	real->fract.length = real->fract.data.length - 1;
}
