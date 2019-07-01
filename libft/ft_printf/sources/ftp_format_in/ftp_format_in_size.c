/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_basic_in_size.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 12:45:28 by bshanae           #+#    #+#             */
/*   Updated: 2019/05/17 19:02:57 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_ft_printf.h"

int				ftp_format_in_size_like(const char *c)
{
	return (*c == 'h' || *c == 'l' || *c == 'L');
}

void			ftp_format_in_size(t_ftp_control *ctrl)
{
	t_ftp_size	temp;

	if (!ft_strncmp(ctrl->buffer.extern_end, "hh", 2))
		temp = ftp_size_hh;
	else if (!ft_strncmp(ctrl->buffer.extern_end, "ll", 2))
		temp = ftp_size_ll;
	else if (*ctrl->buffer.extern_end == 'h')
		temp = ftp_size_h;
	else if (*ctrl->buffer.extern_end == 'l')
		temp = ftp_size_l;
	else if (*ctrl->buffer.extern_end == 'L')
		temp = ftp_size_L;
	else
		return ;
	if (temp == ftp_size_hh || temp == ftp_size_ll)
		ctrl->buffer.extern_end += 2;
	else
		ctrl->buffer.extern_end += 1;
	if (temp > ctrl->format.size)
		ctrl->format.size = temp;
}
