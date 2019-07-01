/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_basic_data_default.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 13:53:23 by bshanae           #+#    #+#             */
/*   Updated: 2019/05/21 18:02:43 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_ft_printf.h"

int				ftp_format_data_in_default(t_ftp_control *ctrl)
{
	t_ftp_type	*format;

	format = &ctrl->format.type;
	if (*format == ftp_type_d || *format == ftp_type_i)
		ftp_format_data_abs(va_arg(*ctrl->arg_ptr, int), ctrl);
	else if (*format >= ftp_type_b && *format <= ftp_type_X)
		ctrl->format.data.whole = va_arg(*ctrl->arg_ptr, unsigned int);
	else if (*format == ftp_type_f)
		ctrl->format.data.real = va_arg(*ctrl->arg_ptr, double);
	else if (*format == ftp_type_c)
		ftp_format_data_abs((unsigned char)va_arg(*ctrl->arg_ptr, int), ctrl);
	else if (*format == ftp_type_s)
		ctrl->format.data.whole =
			(unsigned long long)va_arg(*ctrl->arg_ptr, char *);
	else if (*format == ftp_type_p)
		ctrl->format.data.whole =
			(unsigned long long)va_arg(*ctrl->arg_ptr, void *);
	else
		return (-1);
	return (0);
}
