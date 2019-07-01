/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_format_out.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 13:54:50 by bshanae           #+#    #+#             */
/*   Updated: 2019/05/23 13:54:50 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_ft_printf.h"

int				ftp_format_out(t_ftp_control *ctrl)
{
	t_ftp_type	*format;

	format = &ctrl->format.type;
	if (*format == ftp_type_c || *format == ftp_type_other)
		ftp_format_out_char(ctrl);
	else if (*format == ftp_type_s)
		ftp_format_out_str(ctrl);
	else if (*format == ftp_type_p)
		ftp_format_out_ptr(ctrl);
	else if (*format >= ftp_type_d && *format <= ftp_type_X)
		ftp_format_out_whole(ctrl);
	else if (*format == ftp_type_f)
	{
		if ((ftp_format_out_real(ctrl)) == FTP_ERR_ALLOC)
			return (FTP_ERR_ALLOC);
	}
	return (0);
}
