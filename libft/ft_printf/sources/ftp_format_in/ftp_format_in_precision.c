/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_basic_in_precision.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 12:38:49 by bshanae           #+#    #+#             */
/*   Updated: 2019/05/17 19:02:57 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_ft_printf.h"

int				ftp_format_in_precision_like(const char *c)
{
	return (*c == '.');
}

void			ftp_format_in_precision(t_ftp_control *ctrl)
{
	double		temp;

	ctrl->buffer.extern_end++;
	temp = safe_atof(ctrl->buffer.extern_end);
	ctrl->format.precision = temp > 2147483647 ? -1 : (int)temp;
	while (is_digit(ctrl->buffer.extern_end))
		ctrl->buffer.extern_end++;
}
