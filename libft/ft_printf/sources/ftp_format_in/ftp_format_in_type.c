/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_basic_in_type.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 12:40:40 by bshanae           #+#    #+#             */
/*   Updated: 2019/05/17 19:02:57 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_ft_printf.h"

int				ftp_format_in_type_like(const char *c)
{
	return (*c == 'c' || *c == 's' || *c == 'p' ||
			*c == 'd' || *c == 'i' || *c == 'u' ||
			*c == 'o' || *c == 'x' || *c == 'X' ||
			*c == 'a' || *c == 'A' || *c == 'e' ||
			*c == 'E' || *c == 'f' || *c == 'F' ||
			*c == 'g' || *c == 'G' || *c == 'b');
}

void			ftp_format_in_type(t_ftp_control *ctrl)
{
	if (*ctrl->buffer.extern_end == 'd')
		ctrl->format.type = ftp_type_d;
	else if (*ctrl->buffer.extern_end == 'i')
		ctrl->format.type = ftp_type_i;
	else if (*ctrl->buffer.extern_end == 'u')
	{
		ctrl->format.type = ftp_type_u;
		ctrl->format.flags.plus = 0;
		ctrl->format.flags.space = 0;
	}
	else if (*ctrl->buffer.extern_end == 'o')
		ctrl->format.type = ftp_type_o;
	else if (*ctrl->buffer.extern_end == 'x')
		ctrl->format.type = ftp_type_x;
	else if (*ctrl->buffer.extern_end == 'X')
		ctrl->format.type = ftp_type_X;
	else if (*ctrl->buffer.extern_end == 'f')
		ctrl->format.type = ftp_type_f;
	else
		ftp_format_in_type_add(ctrl);
	if (ctrl->format.type != ftp_type_undef)
		ctrl->buffer.extern_end++;
}

void			ftp_format_in_type_add(t_ftp_control *ctrl)
{
	if (*ctrl->buffer.extern_end == 'c')
		ctrl->format.type = ftp_type_c;
	else if (*ctrl->buffer.extern_end == 's')
		ctrl->format.type = ftp_type_s;
	else if (*ctrl->buffer.extern_end == 'p')
		ctrl->format.type = ftp_type_p;
	else if (*ctrl->buffer.extern_end == 'b')
		ctrl->format.type = ftp_type_b;
}
