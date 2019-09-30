/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_buffer_main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 13:34:50 by bshanae           #+#    #+#             */
/*   Updated: 2019/05/23 13:34:50 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_ft_printf.h"

int					buffer_init(t_ftp_buffer *me, const char *extern_begin)
{
	me->extern_begin = extern_begin;
	me->extern_end = extern_begin;
	if (!(me->begin = (char *)malloc(FTP_BUFF_SIZE)))
		return (-1);
	me->iter = me->begin;
	me->end = me->begin + FTP_BUFF_SIZE;
	me->chars_read = 0;
	me->fd = 1;
	return (0);
}

void				buffer_reset(t_ftp_buffer *me, const char *extern_begin)
{
	me->extern_begin = extern_begin;
	me->extern_end = extern_begin;
	me->iter = me->begin;
	me->chars_read = 0;
}
