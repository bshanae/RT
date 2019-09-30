/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_buffer_functions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 13:34:07 by bshanae           #+#    #+#             */
/*   Updated: 2019/05/23 13:34:07 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_ft_printf.h"

void				buffer_out(t_ftp_buffer *me)
{
	if (me->extern_begin != me->extern_end)
		buffer_extern_in(me);
	if (me->iter == me->begin)
		return ;
	write(me->fd, me->begin, me->iter - me->begin);
	me->iter = me->begin;
}

void				buffer_extern_in(t_ftp_buffer *me)
{
	size_t			diff;

	diff = me->extern_end - me->extern_begin;
	if (!diff)
		return ;
	if (diff > FTP_BUFF_SIZE)
	{
		buffer_out(me);
		write(me->fd, me->extern_begin, diff);
		me->chars_read += diff;
		me->iter = me->begin;
	}
	else if (me->iter + diff >= me->end)
	{
		buffer_out(me);
		buffer_extern_in(me);
	}
	else
	{
		ft_memcpy(me->iter, me->extern_begin, diff);
		me->iter += diff;
		me->chars_read += diff;
	}
	me->extern_begin = me->extern_end;
}

void				buffer_custom_in_char(t_ftp_buffer *me, char c, int len)
{
	if (len <= 0)
		return ;
	if (len > FTP_BUFF_SIZE)
	{
		buffer_out(me);
		fast_char_out(me->fd, c, len);
		return ;
	}
	if (me->iter + len >= me->end)
		buffer_out(me);
	ft_memset(me->iter, c, len);
	me->iter += len;
	me->chars_read += len;
}

void				buffer_custom_in_str(t_ftp_buffer *me, char *str)
{
	int				len;

	if (!str)
		return ;
	if (me->iter + ft_strlen(str) >= me->end)
		buffer_out(me);
	len = ft_strlen(str);
	ft_memcpy(me->iter, str, len);
	me->iter += len;
	me->chars_read += len;
}
