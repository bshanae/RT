/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cl_renderer_render.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 14:03:16 by ashari            #+#    #+#             */
/*   Updated: 2019/10/03 11:10:27 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cl_renderer.h"

static void			static_pre_queue(t_cl_renderer *renderer)
{
	cl_renderer_flag_perform(renderer);
}

static void			static_queue(t_cl_renderer *renderer)
{
	int				error;

	error = clEnqueueNDRangeKernel(renderer->builder->queue,
		renderer->builder->kernel, 1, NULL,
		&renderer->pixel_number, NULL, 0, NULL, NULL);
	rt_assert(error == 0, "Renderer : Runtime error");
}

static void			static_focus_request(t_cl_renderer *renderer)
{
	cl_args_list_read(renderer->args, cl_arg_camera);
	renderer->data.camera->focus_request = 0;
	cl_renderer_flag_set(renderer, cl_flag_update_camera);
	cl_renderer_flag_set(renderer, cl_flag_reset_samples);
}

static void			static_post_queue(t_cl_renderer *renderer)
{
	cl_args_list_read(renderer->args, cl_arg_image);
	if (renderer->data.camera->select_request)
	{
		cl_args_list_read(renderer->args, cl_arg_camera);
		scene_select(renderer->data.scene,
				renderer->data.camera->select_request_object);
		renderer->data.camera->select_request = 0;
		renderer->data.camera->select_request_object = -1;
		cl_renderer_flag_set(renderer, cl_flag_update_camera);
		cl_renderer_flag_set(renderer, cl_flag_update_scene);
		cl_renderer_flag_set(renderer, cl_flag_reset_samples);
	}
	if (renderer->data.camera->focus_request)
		static_focus_request(renderer);
	if (!renderer->data.settings.motion_blur)
		renderer->data.settings.sample_count++;
	else
		renderer->data.settings.motion_blur_sample_count =
			ft_min(renderer->data.settings.motion_blur_sample_count + 1,
					RT_SAMPLE_ARRAY_LENGTH);
	cl_renderer_flag_set(renderer, cl_flag_update_settings);
	gtk_image_set_from_pixbuf(renderer->image->image,
		renderer->image->gdk_buffer);
}

#ifndef RT_OPEN_CL_DISABLED

void				cl_renderer_render(t_cl_renderer *renderer)
{
	t_rt_settings	*settings;

	settings = &renderer->data.settings;
	static_pre_queue(renderer);
	if (settings->sample_count > settings->sample_limit)
		return ;
	static_queue(renderer);
	static_post_queue(renderer);
}

#else

void				cl_renderer_render(t_cl_renderer *renderer)
{

}

#endif
