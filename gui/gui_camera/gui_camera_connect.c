/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_camera_connect.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 18:27:36 by bshanae           #+#    #+#             */
/*   Updated: 2019/10/17 13:59:27 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_camera.h"

void						gui_camera_connect(t_gui_camera *camera, ...)
{
	va_list					args;

	va_start(args, camera);
	camera->ptr_camera = va_arg(args, t_camera *);
	camera->ptr_light = va_arg(args, t_rt_light_mod *);
	va_end(args);
	camera->connected = rt_true;
}
