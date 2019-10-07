/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_default.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 10:09:06 by ashari            #+#    #+#             */
/*   Updated: 2019/10/07 10:09:07 by ashari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

void				camera_default(t_camera *camera)
{
	camera->position = (RT_F4_API){0., 0., 0.};
	camera->rotation = (RT_F4_API){0., 0., 0.};
	camera->forward = (RT_F4_API){0., 0., -1.
		* camera->width / (tan((M_PI / 3.) / 2.))};
	camera->forward_backup = camera->forward;
	camera->axis_x = (RT_F4_API){1., 0., 0.};
	camera->axis_y = (RT_F4_API){0., 1., 0.};
	camera->axis_z = (RT_F4_API){0., 0., 1.};
	camera->filter_antialiasing = RT_ANTIALIASING;
	camera->filter_mod = RT_FILTER;
	camera->focus = RT_FOCUS;
	camera->aperture_size = RT_APERTURE_SIZE;
	camera->focal_length = RT_FOCAL_LENGTH;
	camera->focus_request = 0;
	camera->select_request = 0;
	camera->select_request_object = -1;
}
