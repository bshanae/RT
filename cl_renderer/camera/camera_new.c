/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 13:33:56 by ashari            #+#    #+#             */
/*   Updated: 2019/09/28 13:33:58 by ashari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

t_camera			*camera_new(INT_REF width, INT_REF height)
{
	t_camera		*new;

	new = (t_camera *)rt_malloc(sizeof(t_camera));
	new->position = (RT_F4_API){0., 0., 0.};
	new->rotation = (RT_F4_API){0., 0., 0.};
	new->forward = (RT_F4_API){0., 0., -1.
							* *width / (tan((M_PI / 3.) / 2.))};
	new->forward_backup = new->forward;
	new->axis_x = (RT_F4_API){1., 0., 0.};
	new->axis_y = (RT_F4_API){0., 1., 0.};
	new->axis_z = (RT_F4_API){0., 0., 1.};
	new->width = *width;
	new->height = *height;
	new->filter_antialiasing = RT_ANTIALIASING;
	new->filter_mod = RT_FILTER;
	new->focus = RT_FOCUS;
	new->aperture_size = RT_APERTURE_SIZE;
	new->focal_length = RT_FOCAL_LENGTH;
	new->focus_request = 0;
	new->select_request = 0;
	new->select_request_object = -1;
	return (new);
}
