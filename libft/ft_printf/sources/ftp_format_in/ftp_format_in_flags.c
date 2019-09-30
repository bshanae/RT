/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_basic_in_flags.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 12:26:53 by bshanae           #+#    #+#             */
/*   Updated: 2019/05/18 21:35:31 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_ft_printf.h"

int				ftp_format_in_flags_like(const char *c)
{
	return (*c == '-' || *c == '+' || *c == ' ' || *c == '#' || *c == '0');
}

void			ftp_format_in_flags(t_ftp_control *ctrl)
{
	while (1)
	{
		if (*ctrl->buffer.extern_end == '-')
		{
			ctrl->format.flags.minus = 1;
			ctrl->format.flags.zero = 0;
		}
		else if (*ctrl->buffer.extern_end == '+')
		{
			ctrl->format.flags.plus = 1;
			ctrl->format.flags.space = 0;
		}
		else if (*ctrl->buffer.extern_end == '-')
			ctrl->format.flags.minus = 1;
		else if (*ctrl->buffer.extern_end == ' ')
			ctrl->format.flags.space = !ctrl->format.flags.plus;
		else if (*ctrl->buffer.extern_end == '#')
			ctrl->format.flags.hash = 1;
		else if (*ctrl->buffer.extern_end == '0')
			ctrl->format.flags.zero = !ctrl->format.flags.minus;
		else
			return ;
		ctrl->buffer.extern_end++;
	}
}
