/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_format_out_real_init.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 13:55:31 by bshanae           #+#    #+#             */
/*   Updated: 2019/05/23 13:55:31 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_ft_printf.h"

static void			init_ws
	(t_real_params *real, t_ftp_control *c, t_ftp_whitespaces *ws)
{
	real->force_point = c->format.flags.hash;
	ft_bzero(real->sign.data, 2);
	if (c->format.flags.space && ft_strcmp(real->exception.data, "nan"))
		real->sign.data[0] = ' ';
	else if (c->format.flags.plus && ft_strcmp(real->exception.data, "nan"))
		real->sign.data[0] = '+';
	if (real->represent.memory.sign)
		real->sign.data[0] = '-';
	real->sign.length = ft_strlen(real->sign.data);
	if (real->exception.is_present)
	{
		ws->prec_num = 0;
		ws->wid_type = ' ';
		ws->wid_num = ft_max(0,
			c->format.width - real->exception.length - real->sign.length);
	}
	else
	{
		ws->prec_num = c->format.precision == -1 ? 6 : c->format.precision;
		ws->wid_type = c->format.flags.zero ? '0' : ' ';
		ws->wid_num = ft_max(0, c->format.width - ws->prec_num -
								real->whole.length - real->sign.length -
								(ws->prec_num != 0) -
								(real->force_point && !ws->prec_num));
	}
}

int					ftp_format_out_real_init
	(t_real_params *real, t_ftp_control *ctrl, t_ftp_whitespaces *ws)
{
	real->represent.real = ctrl->format.data.real;
	real->extract_exponent = real->represent.memory.exponent - 16383;
	ftp_format_out_real_exceptions(real);
	if (!real->exception.is_present)
		ftp_format_out_real_convert(real);
	if ((real->whole.length == -1 || real->fract.length == -2)
		&& !real->exception.is_present)
		return (FTP_ERR_ALLOC);
	ftp_format_out_real_round(real,
		ctrl->format.precision == -1 ? 6 : ctrl->format.precision);
	init_ws(real, ctrl, ws);
	return (0);
}
