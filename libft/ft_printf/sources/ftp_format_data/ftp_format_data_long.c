/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_basic_data_long.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 13:52:55 by bshanae           #+#    #+#             */
/*   Updated: 2019/05/17 19:00:02 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_ft_printf.h"

int				ftp_format_data_in_long(t_ftp_control *ctrl)
{
	t_ftp_type	*format;

	format = &ctrl->format.type;
	if (*format == ftp_type_d || *format == ftp_type_i)
		ftp_format_data_abs(va_arg(*ctrl->arg_ptr, long), ctrl);
	else if (*format >= ftp_type_b && *format <= ftp_type_X)
		ctrl->format.data.whole = va_arg(*ctrl->arg_ptr, unsigned long);
	else
		return (-1);
	return (0);
}

int				ftp_format_data_in_l_long(t_ftp_control *ctrl)
{
	t_ftp_type	*format;

	format = &ctrl->format.type;
	if (*format == ftp_type_d || *format == ftp_type_i)
		ftp_format_data_abs(va_arg(*ctrl->arg_ptr, long long), ctrl);
	else if (*format >= ftp_type_b && *format <= ftp_type_X)
		ctrl->format.data.whole =
			va_arg(*ctrl->arg_ptr, unsigned long long);
	else
		return (-1);
	return (0);
}

int				ftp_format_data_in_l_double(t_ftp_control *ctrl)
{
	t_ftp_type	*format;

	format = &ctrl->format.type;
	if (*format == ftp_type_f)
		ctrl->format.data.real = va_arg(*ctrl->arg_ptr, long double);
	else
		return (-1);
	return (0);
}
