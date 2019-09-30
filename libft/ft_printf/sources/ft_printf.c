/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 13:28:17 by bshanae           #+#    #+#             */
/*   Updated: 2019/05/23 13:30:55 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_ft_printf.h"

int								ft_printf(const char *format, ...)
{
	static t_ftp_control		ctrl;
	va_list						args;

	va_start(args, format);
	if ((ftp_control_init(&ctrl, format, &args)) == FTP_ERR_ALLOC)
		return (FTP_ERR_ALLOC);
	while (*ctrl.buffer.extern_end)
		if (*ctrl.buffer.extern_end == '%')
		{
			if ((ftp_control_format_run(&ctrl)) == FTP_ERR_ALLOC)
				return (FTP_ERR_ALLOC);
		}
		else if (*ctrl.buffer.extern_end == '{')
			ftp_control_style(&ctrl);
		else if (*ctrl.buffer.extern_end == '\n')
		{
			ctrl.buffer.extern_end++;
			buffer_out(&ctrl.buffer);
		}
		else
			ctrl.buffer.extern_end++;
	va_end(args);
	buffer_out(&ctrl.buffer);
	ftp_control_style_clean(&ctrl);
	return (ctrl.buffer.chars_read);
}
