/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cl_renderer_change_x.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 14:02:21 by ashari            #+#    #+#             */
/*   Updated: 2019/09/28 14:02:22 by ashari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cl_renderer.h"

void				cl_renderer_change_tracing_mod(
					t_cl_renderer *renderer, t_rt_tracing_mod mod)
{
	renderer->data.settings.tracing_mod = mod;
	renderer->data.settings.tracing_mod_mask = mod == rt_tracing_rm ?
		RT_OBJECT_RM : RT_OBJECT_RT;
	scene_update(renderer->data.scene);
	cl_renderer_flag_set(renderer, cl_flag_update_settings);
	cl_renderer_flag_set(renderer, cl_flag_update_scene);
	cl_renderer_flag_set(renderer, cl_flag_reset_samples);
}

void				cl_renderer_change_light_mod(
					t_cl_renderer *renderer, t_rt_light_mod mod)
{
	renderer->data.settings.light_mod = mod;
	cl_renderer_flag_set(renderer, cl_flag_update_settings);
	cl_renderer_flag_set(renderer, cl_flag_reset_samples);
}
