/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cl_renderer_load.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 14:02:51 by ashari            #+#    #+#             */
/*   Updated: 2019/09/28 14:02:52 by ashari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cl_renderer.h"

void				cl_renderer_load(
					t_cl_renderer *renderer, const char *path)
{
	scene_clear(renderer->data.scene);
	load_scene(renderer, path);
	scene_update(renderer->data.scene);
	cl_renderer_camera_save(renderer);
}
