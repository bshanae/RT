/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_format_out_real.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 14:12:52 by bshanae           #+#    #+#             */
/*   Updated: 2019/05/23 14:12:52 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_ft_printf.h"

int						ftp_format_out_real(t_ftp_control *ctrl)
{
	t_real_params		real;
	t_ftp_whitespaces	ws;

	if (ftp_format_out_real_init(&real, ctrl, &ws) == FTP_ERR_ALLOC)
		return (FTP_ERR_ALLOC);
	if (ctrl->format.flags.minus)
	{
		if (real.sign.length)
			buffer_custom_in_char(&ctrl->buffer, real.sign.data[0], 1);
		ftp_format_out_real_out(&ctrl->buffer, &real, ws.prec_num);
		buffer_custom_in_char(&ctrl->buffer, ws.wid_type, ws.wid_num);
	}
	else
	{
		if (ws.wid_type == '0' && real.sign.length)
			buffer_custom_in_char(&ctrl->buffer, real.sign.data[0], 1);
		buffer_custom_in_char(&ctrl->buffer, ws.wid_type, ws.wid_num);
		if (ws.wid_type != '0' && real.sign.length)
			buffer_custom_in_char(&ctrl->buffer, real.sign.data[0], 1);
		ftp_format_out_real_out(&ctrl->buffer, &real, ws.prec_num);
	}
	long_destroy(&real.whole.data);
	long_destroy(&real.fract.data);
	return (0);
}
