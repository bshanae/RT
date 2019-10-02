/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_scene_common_connect.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 16:42:43 by bshanae           #+#    #+#             */
/*   Updated: 2019/10/02 16:42:43 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_scene_common.h"

void				gui_scene_common_connect(t_gui_scene_common *common, ...)
{
	va_list			args;

	va_start(args, common);
	common->ptr_scene = va_arg(args, t_scene *);
	common->ptr_light = va_arg(args, t_rt_light_mod *);
	va_end(args);
	common->connected = rt_true;
}
