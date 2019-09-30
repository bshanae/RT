/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_control_functions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 14:22:05 by bshanae           #+#    #+#             */
/*   Updated: 2019/05/23 13:40:11 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_ft_printf.h"

void				ftp_control_format_reset(t_ftp_control *me)
{
	me->format.flags.minus = 0;
	me->format.flags.plus = 0;
	me->format.flags.space = 0;
	me->format.flags.zero = 0;
	me->format.flags.hash = 0;
	me->format.width = -1;
	me->format.precision = -1;
	me->format.size = ftp_size_undef;
	me->format.type = ftp_type_undef;
	me->format.data.whole = 0;
	me->format.data.whole_sign = 1;
	ft_bzero(me->format.data.whole_str, FTP_STR_NUM_SIZE);
	me->format.data.real = 0;
}

int					ftp_control_format_run(t_ftp_control *me)
{
	ftp_control_format_reset(me);
	buffer_extern_in(&me->buffer);
	me->buffer.extern_end++;
	ftp_format_in(me);
	if (me->format.size == ftp_size_undef)
		me->format.size = ftp_size_default;
	if (me->format.type != ftp_type_other)
		ftp_format_data(me);
	me->buffer.extern_begin = me->buffer.extern_end;
	if (me->format.type != ftp_type_undef)
		return (ftp_format_out(me));
	return (0);
}
