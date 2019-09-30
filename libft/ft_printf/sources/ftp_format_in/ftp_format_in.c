/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_format_in.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 13:50:04 by bshanae           #+#    #+#             */
/*   Updated: 2019/05/23 13:50:04 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_ft_printf.h"

void			ftp_format_in(t_ftp_control *ctrl)
{
	while (*ctrl->buffer.extern_end)
	{
		if (ftp_format_in_additional(ctrl))
			return ;
		else if (ftp_format_in_flags_like(ctrl->buffer.extern_end))
			ftp_format_in_flags(ctrl);
		else if (ftp_format_in_width_like(ctrl->buffer.extern_end))
			ftp_format_in_width(ctrl);
		else if (ftp_format_in_precision_like(ctrl->buffer.extern_end))
			ftp_format_in_precision(ctrl);
		else if (ftp_format_in_size_like(ctrl->buffer.extern_end))
			ftp_format_in_size(ctrl);
		else if (ftp_format_in_type_like(ctrl->buffer.extern_end))
		{
			ftp_format_in_type(ctrl);
			break ;
		}
		else
		{
			ctrl->format.type = ftp_type_other;
			ctrl->format.data.whole = *(ctrl->buffer.extern_end++);
			return ;
		}
	}
}
