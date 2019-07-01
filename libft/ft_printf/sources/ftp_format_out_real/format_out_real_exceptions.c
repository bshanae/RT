/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_out_real_exceptions.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 14:14:59 by bshanae           #+#    #+#             */
/*   Updated: 2019/05/23 14:42:25 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_ft_printf.h"

void				ftp_format_out_real_exceptions(t_real_params *real)
{
	real->exception.is_present = 0;
	ft_bzero(real->exception.data, 5);
	if (real->represent.memory.mantissa == (unsigned long)1 << 63u &&
		real->represent.memory.exponent == 0x7FFF)
	{
		real->exception.is_present = 1;
		if (real->represent.memory.sign)
			real->sign.data[0] = '-';
		ft_strcpy(real->exception.data, "inf");
	}
	else if (real->represent.memory.mantissa &&
		real->represent.memory.exponent == 0x7FFF)
	{
		real->exception.is_present = 1;
		if (real->represent.memory.sign)
			real->sign.data[0] = '-';
		ft_strcpy(real->exception.data, "nan");
	}
	else
		return ;
	real->whole.data.length = 0;
	real->fract.data.length = 0;
	real->whole.length = 0;
	real->fract.length = 0;
	real->exception.length = ft_strlen(real->exception.data);
}
