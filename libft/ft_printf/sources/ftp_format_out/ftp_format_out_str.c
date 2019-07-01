/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_format_out_str.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 13:53:11 by bshanae           #+#    #+#             */
/*   Updated: 2019/05/23 13:53:11 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_ft_printf.h"

static void				helper(t_ftp_control *ctrl, int len)
{
	if (ctrl->format.data.whole)
		ft_memcpy(ctrl->buffer.iter, (u_char *)ctrl->format.data.whole, len);
	else
		ft_memcpy(ctrl->buffer.iter, "(null)", len);
	ctrl->buffer.iter += len;
	ctrl->buffer.chars_read += len;
}

void					ftp_format_out_str(t_ftp_control *ctrl)
{
	t_ftp_whitespaces	ws;
	int					len;

	len = ctrl->format.data.whole ?
		ft_strlen((char *)ctrl->format.data.whole) : 6;
	if (ctrl->format.precision != -1)
		len = ft_min(len, ctrl->format.precision);
	ws.wid_type = ctrl->format.flags.zero ? '0' : ' ';
	ws.wid_num = ft_max(0, ctrl->format.width - len);
	if (ctrl->format.flags.minus)
	{
		helper(ctrl, len);
		buffer_custom_in_char(&ctrl->buffer, ws.wid_type, ws.wid_num);
	}
	else
	{
		buffer_custom_in_char(&ctrl->buffer, ws.wid_type, ws.wid_num);
		helper(ctrl, len);
	}
}
