/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_basic_in_width.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 12:33:59 by bshanae           #+#    #+#             */
/*   Updated: 2019/05/17 19:02:57 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_ft_printf.h"

int				ftp_format_in_width_like(const char *c)
{
	return (*c >= '0' && *c <= '9');
}

void			ftp_format_in_width(t_ftp_control *ctrl)
{
	double		temp;

	temp = safe_atof(ctrl->buffer.extern_end);
	ctrl->format.width = temp > 2147483647 ? -1 : (int)temp;
	while (is_digit(ctrl->buffer.extern_end))
		ctrl->buffer.extern_end++;
}
