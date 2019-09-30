/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_control_functions_style.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 13:40:28 by bshanae           #+#    #+#             */
/*   Updated: 2019/05/23 13:40:28 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_ft_printf.h"

static void			style_helper(t_ftp_control *ctrl, char *str, int pass)
{
	if (ctrl->buffer.fd == 1)
		buffer_custom_in_str(&ctrl->buffer, str);
	ft_bzero(ctrl->color.str, 10);
	ft_strcpy(ctrl->color.str, str);
	ctrl->buffer.extern_end += pass;
	ctrl->color.is_const = *ctrl->buffer.extern_end == '!';
	ctrl->buffer.extern_end += 1 + (*ctrl->buffer.extern_end == '!');
	ctrl->buffer.extern_begin = ctrl->buffer.extern_end;
}

static void			style_add(t_ftp_control *me)
{
	if (!ft_strncmp(me->buffer.extern_end, "bold", 4))
		style_helper(me, FTP_BOLD, 4);
	else if (!ft_strncmp(me->buffer.extern_end, "underline", 9))
		style_helper(me, FTP_UNDERLINE, 9);
	else if (!ft_strncmp(me->buffer.extern_end, "reset", 5))
		style_helper(me, FTP_RESET, 5);
}

void				ftp_control_style(t_ftp_control *me)
{
	buffer_extern_in(&me->buffer);
	if (*(++me->buffer.extern_end) == '{')
	{
		buffer_custom_in_char(&me->buffer, '{', 1);
		me->buffer.extern_end++;
	}
	else if (!ft_strncmp(me->buffer.extern_end, "red", 3))
		style_helper(me, FTP_RED, 3);
	else if (!ft_strncmp(me->buffer.extern_end, "green", 5))
		style_helper(me, FTP_GREEN, 5);
	else if (!ft_strncmp(me->buffer.extern_end, "yellow", 6))
		style_helper(me, FTP_YELLOW, 6);
	else if (!ft_strncmp(me->buffer.extern_end, "blue", 4))
		style_helper(me, FTP_BLUE, 4);
	else if (!ft_strncmp(me->buffer.extern_end, "magenta", 7))
		style_helper(me, FTP_MAGENTA, 7);
	else if (!ft_strncmp(me->buffer.extern_end, "cyan", 4))
		style_helper(me, FTP_CYAN, 4);
	else if (!ft_strncmp(me->buffer.extern_end, "purple", 6))
		style_helper(me, FTP_PURPLE, 6);
	else
		style_add(me);
}

void				ftp_control_style_clean(t_ftp_control *me)
{
	if (me->color.str[0] && !me->color.is_const && me->buffer.fd == 1)
		buffer_custom_in_str(&me->buffer, FTP_RESET);
}
