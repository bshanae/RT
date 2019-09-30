/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_format_out_char.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 13:53:26 by bshanae           #+#    #+#             */
/*   Updated: 2019/05/23 13:53:26 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_ft_printf.h"

void				ftp_format_out_char(t_ftp_control *ctrl)
{
	t_ftp_whitespaces	ws;

	ws.wid_num = ft_max(0, ctrl->format.width - 1);
	ws.wid_type = ctrl->format.flags.zero ? '0' : ' ';
	if (ctrl->format.flags.minus)
	{
		*(ctrl->buffer.iter++) = (unsigned char)ctrl->format.data.whole;
		ctrl->buffer.chars_read++;
		buffer_custom_in_char(&ctrl->buffer, ws.wid_type, ws.wid_num);
	}
	else
	{
		buffer_custom_in_char(&ctrl->buffer, ws.wid_type, ws.wid_num);
		*(ctrl->buffer.iter++) = (unsigned char)ctrl->format.data.whole;
		ctrl->buffer.chars_read++;
	}
}
