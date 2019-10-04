/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cl_renderer_camera_request_x.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 14:02:01 by ashari            #+#    #+#             */
/*   Updated: 2019/10/01 18:09:14 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cl_renderer.h"

void				cl_renderer_camera_request_focus(
					t_cl_renderer *renderer, int x, int y)
{
	cl_renderer_flag_set(renderer, cl_flag_update_camera);
	cl_renderer_flag_set(renderer, cl_flag_reset_samples);
	camera_request_focus(renderer->data.camera, x, y);
}

void				cl_renderer_camera_request_select(
					t_cl_renderer *renderer, int x, int y)
{
	cl_renderer_flag_set(renderer, cl_flag_update_camera);
	cl_renderer_flag_set(renderer, cl_flag_update_scene);
	cl_renderer_flag_set(renderer, cl_flag_reset_samples);
	camera_request_select(renderer->data.camera, x, y);
}
