/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cl_renderer_load.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbosmer <sbosmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 14:02:51 by ashari            #+#    #+#             */
/*   Updated: 2019/10/17 13:59:27 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cl_renderer.h"

void				cl_renderer_load(
					t_cl_renderer *renderer, const char *path)
{
	camera_default(renderer->data.camera);
	scene_clear(renderer->data.scene);
	json_load(renderer, path);
	scene_update(renderer->data.scene);
	cl_renderer_camera_save(renderer);
	cl_renderer_flag_set(renderer, cl_flag_update_camera);
	cl_renderer_flag_set(renderer, cl_flag_update_scene);
	cl_renderer_flag_set(renderer, cl_flag_update_settings);
	cl_renderer_flag_set(renderer, cl_flag_reset_samples);
	camera_apply(renderer->data.camera);
}
