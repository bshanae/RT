/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cl_renderer_flag_x.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 14:02:33 by ashari            #+#    #+#             */
/*   Updated: 2019/10/01 18:09:14 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cl_renderer.h"

void						cl_renderer_flag_set(
							t_cl_renderer *renderer,
							t_cl_renderer_flag flag)
{
	if (flag == cl_flag_update_camera)
		renderer->flags.update_camera = 1;
	else if (flag == cl_flag_update_scene)
		renderer->flags.update_scene = 1;
	else if (flag == cl_flag_update_settings)
		renderer->flags.update_settings = 1;
	else if (flag == cl_flag_reset_samples)
		renderer->flags.reset_samples = 1;
}

void						cl_renderer_flag_perform(t_cl_renderer *renderer)
{
	if (renderer->flags.update_camera)
		renderer->args->array[cl_arg_camera].update_need = 1;
	if (renderer->flags.update_scene)
		renderer->args->array[cl_arg_scene].update_need = 1;
	if (renderer->flags.update_settings)
		renderer->args->array[cl_arg_settings].update_need = 1;
	if (renderer->flags.reset_samples)
	{
		renderer->data.settings.sample_count = 1;
		renderer->args->array[cl_arg_settings].update_need = 1;
	}
	cl_arg_list_update(renderer->args);
	ft_bzero(&renderer->flags, sizeof(t_cl_renderer_flag_list));
}
