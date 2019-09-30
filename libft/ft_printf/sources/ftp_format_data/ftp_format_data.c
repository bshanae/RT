/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_format_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 13:46:35 by bshanae           #+#    #+#             */
/*   Updated: 2019/05/23 13:46:37 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_ft_printf.h"

void		ftp_format_data_abs(long long value, t_ftp_control *ctrl)
{
	if (value >= 0)
		ctrl->format.data.whole = value;
	else
	{
		ctrl->format.data.whole_sign = -1;
		ctrl->format.data.whole = ((value + 1) * -1) + 1;
	}
}

void		ftp_format_data(t_ftp_control *ctrl)
{
	int		res;

	res = -1;
	if (ctrl->format.size == ftp_size_hh)
		res = ftp_format_data_in_s_short(ctrl);
	else if (ctrl->format.size == ftp_size_h)
		res = ftp_format_data_in_short(ctrl);
	else if (ctrl->format.size == ftp_size_default)
		res = ftp_format_data_in_default(ctrl);
	else if (ctrl->format.size == ftp_size_l)
		res = ftp_format_data_in_long(ctrl);
	else if (ctrl->format.size == ftp_size_ll)
		res = ftp_format_data_in_l_long(ctrl);
	else if (ctrl->format.size == ftp_size_L)
		res = ftp_format_data_in_l_double(ctrl);
	if (res == -1)
		res = ftp_format_data_in_default(ctrl);
	ctrl->format.size = res;
}
