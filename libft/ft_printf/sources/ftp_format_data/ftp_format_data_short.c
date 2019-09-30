/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_basic_data_short.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 13:53:09 by bshanae           #+#    #+#             */
/*   Updated: 2019/05/17 18:59:53 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_ft_printf.h"

int				ftp_format_data_in_short(t_ftp_control *ctrl)
{
	t_ftp_type	*format;

	format = &ctrl->format.type;
	if (*format == ftp_type_d || *format == ftp_type_i)
		ftp_format_data_abs((short)va_arg(*ctrl->arg_ptr, int), ctrl);
	else if (*format >= ftp_type_b && *format <= ftp_type_X)
		ctrl->format.data.whole = (u_short)va_arg(*ctrl->arg_ptr, unsigned int);
	else
		return (-1);
	return (0);
}

int				ftp_format_data_in_s_short(t_ftp_control *ctrl)
{
	t_ftp_type	*format;

	format = &ctrl->format.type;
	if (*format == ftp_type_d || *format == ftp_type_i)
		ftp_format_data_abs((char)va_arg(*ctrl->arg_ptr, int), ctrl);
	else if (*format >= ftp_type_b && *format <= ftp_type_X)
		ctrl->format.data.whole = (u_char)va_arg(*ctrl->arg_ptr, unsigned int);
	else
		return (-1);
	return (0);
}
