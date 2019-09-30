/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_format_out_whole_out.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 13:56:48 by bshanae           #+#    #+#             */
/*   Updated: 2019/05/23 13:56:48 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_ft_printf.h"

static void				print_special
	(t_ftp_buffer *buff, t_ftp_whole_params *params)
{
	if (!params->spec_len)
		return ;
	ft_memcpy(buff->iter, params->spec_char, params->spec_len);
	buff->iter += params->spec_len;
	buff->chars_read += params->spec_len;
}

static void				print_num
	(t_ftp_buffer *buff, t_ftp_control *ctrl, int len)
{
	ft_memcpy(buff->iter,
		ctrl->format.data.whole_str + FTP_STR_NUM_SIZE - len, len);
	buff->iter += len;
	buff->chars_read += len;
}

void					ftp_format_out_whole_out
	(t_ftp_whole_params *whole, t_ftp_control *ctrl)
{
	t_ftp_whitespaces	ws;

	ws.prec_num = ft_max(0, (int)ctrl->format.precision - whole->num_len);
	if (ws.prec_num > 0 && ctrl->format.type == ftp_type_o)
		whole->spec_len = 0;
	ws.wid_type = ctrl->format.flags.zero ? '0' : ' ';
	ws.wid_num = ft_max(0, (int)ctrl->format.width - ws.prec_num -
		whole->num_len - whole->spec_len);
	if (ctrl->format.flags.minus)
	{
		print_special(&ctrl->buffer, whole);
		buffer_custom_in_char(&ctrl->buffer, '0', ws.prec_num);
		print_num(&ctrl->buffer, ctrl, whole->num_len);
		buffer_custom_in_char(&ctrl->buffer, ws.wid_type, ws.wid_num);
	}
	else
	{
		if (ws.wid_type == '0')
			print_special(&ctrl->buffer, whole);
		buffer_custom_in_char(&ctrl->buffer, ws.wid_type, ws.wid_num);
		if (ws.wid_type != '0')
			print_special(&ctrl->buffer, whole);
		buffer_custom_in_char(&ctrl->buffer, '0', ws.prec_num);
		print_num(&ctrl->buffer, ctrl, whole->num_len);
	}
}
