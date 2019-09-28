/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_request_x.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 13:34:04 by ashari            #+#    #+#             */
/*   Updated: 2019/09/28 13:34:05 by ashari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

void				camera_request_focus(t_camera *camera, int x, int y)
{
	camera->focus_request = 1;
	camera->request_value.x = x;
	camera->request_value.y = y;
}

void				camera_request_select(t_camera *camera, int x, int y)
{
	camera->select_request = 1;
	camera->request_value.x = x;
	camera->request_value.y = y;
}
