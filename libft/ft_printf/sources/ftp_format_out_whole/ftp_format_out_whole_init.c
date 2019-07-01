/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_format_out_whole_init.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 13:59:36 by bshanae           #+#    #+#             */
/*   Updated: 2019/05/23 13:59:36 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_ft_printf.h"

static void		get_base(t_ftp_whole_params *whole, t_ftp_control *ctrl)
{
	if (ctrl->format.type == ftp_type_b)
		whole->base = 2;
	else if (ctrl->format.type == ftp_type_o)
		whole->base = 8;
	else if (ctrl->format.type >= ftp_type_x && ctrl->format.type <= ftp_type_p)
		whole->base = 16;
	else
		whole->base = 10;
}

static void		spec_char(t_ftp_whole_params *whole, t_ftp_control *ctrl)
{
	ft_bzero(whole->spec_char, 3);
	if (whole->base == 10)
	{
		if (ctrl->format.data.whole_sign == -1)
			whole->spec_char[0] = '-';
		else if (ctrl->format.flags.plus)
			whole->spec_char[0] = '+';
		else if (ctrl->format.flags.space)
			whole->spec_char[0] = ' ';
		whole->spec_len = ft_strlen(whole->spec_char);
		return ;
	}
	if (ctrl->format.flags.hash &&
		ctrl->format.type >= ftp_type_o && ctrl->format.type <= ftp_type_p &&
		(whole->copy || ctrl->format.type == ftp_type_p))
		whole->spec_char[0] = '0';
	if (ctrl->format.flags.hash &&
		ctrl->format.type >= ftp_type_x && ctrl->format.type <= ftp_type_p &&
		(whole->copy || ctrl->format.type == ftp_type_p))
		whole->spec_char[1] = 'x' + (whole->is_upper ? -32 : 0);
	whole->spec_len = ft_strlen(whole->spec_char);
}

void			ftp_format_out_whole_init
	(t_ftp_whole_params *whole, t_ftp_control *ctrl)
{
	whole->copy = ctrl->format.data.whole;
	get_base(whole, ctrl);
	whole->is_upper = ctrl->format.type == ftp_type_X;
	spec_char(whole, ctrl);
	if (ctrl->format.type == ftp_type_b)
	{
		ft_memcpy(whole->spec_char, "0b", 2);
		whole->spec_len = 2;
		ctrl->format.flags.hash = 1;
		ctrl->format.flags.zero = 1;
		if (ctrl->format.size == ftp_size_h)
			ctrl->format.width = ft_max((int)ctrl->format.width, 8);
		else if (ctrl->format.size == ftp_size_hh)
			ctrl->format.width = ft_max((int)ctrl->format.width, 16);
		else if (ctrl->format.size == ftp_size_default)
			ctrl->format.width = ft_max((int)ctrl->format.width, 32);
		else if (ctrl->format.size == ftp_size_l)
			ctrl->format.width = ft_max((int)ctrl->format.width, 64);
		else if (ctrl->format.size == ftp_size_ll)
			ctrl->format.width = ft_max((int)ctrl->format.width, 64);
	}
}
