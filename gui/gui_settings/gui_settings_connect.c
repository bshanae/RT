/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_settings_connect.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 17:00:57 by bshanae           #+#    #+#             */
/*   Updated: 2019/10/02 17:01:00 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_settings.h"

void				gui_settings_connect(t_gui_settings *settings, ...)
{
	va_list			args;

	va_start(args, settings);
	settings->ptr_settings = va_arg(args, t_rt_settings *);
	va_end(args);
	settings->connected = rt_true;
}
