/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_control_definition.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 13:43:15 by bshanae           #+#    #+#             */
/*   Updated: 2019/05/23 13:43:15 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_ft_printf.h"

int				ftp_control_init
	(t_ftp_control *me, const char *extern_begin, va_list *arg_ptr)
{
	if (!extern_begin)
		return (FTP_ERR_FORMAT);
	if (!me->buffer.begin)
	{
		if ((buffer_init(&me->buffer, extern_begin)) == -1)
			return (FTP_ERR_ALLOC);
	}
	else
		buffer_reset(&me->buffer, extern_begin);
	me->arg_ptr = arg_ptr;
	if (!me->color.is_const)
		ft_bzero(me->color.str, 10);
	else
	{
		if (me->buffer.iter + ft_strlen(me->color.str) >= me->buffer.end)
			buffer_out(&me->buffer);
		ft_memcpy(me->buffer.iter,
			me->color.str, ft_strlen(me->color.str));
		me->buffer.iter += ft_strlen(me->color.str);
	}
	return (0);
}
