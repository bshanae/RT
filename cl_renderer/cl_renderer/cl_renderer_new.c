/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cl_renderer_new.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 14:02:58 by ashari            #+#    #+#             */
/*   Updated: 2019/10/17 13:59:27 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cl_renderer.h"

static void				static_data_init(t_cl_renderer *renderer)
{
	int					i;

	printf("Renderer : Initializing camera\n");
	renderer->data.camera =
		camera_new(&renderer->image->width, &renderer->image->height);
	renderer->data.camera_unmodified =
		camera_new(&renderer->image->width, &renderer->image->height);
	printf("Renderer : Initializing scene\n");
	renderer->data.scene = scene_new(&renderer->data.settings.tracing_mod,
		&renderer->data.settings.tracing_mod_mask);
	renderer->data.image = renderer->image->color_buffer;
	cl_renderer_settings_init(&renderer->data.settings);
	printf("Renderer : Initializing rng seeds\n");
	i = 0;
	renderer->data.rng_state = rt_malloc(
			sizeof(u_long) * renderer->pixel_number);
	srand(21);
	while (i < renderer->pixel_number)
		renderer->data.rng_state[i++] = rand();
}

static void				static_set_args(t_cl_renderer *renderer)
{
	printf("Renderer : Initializing arguments\n");
	cl_arg_list_push(renderer->args, renderer->data.camera,
		sizeof(t_camera), CL_MEM_READ_WRITE);
	cl_arg_list_push(renderer->args, renderer->data.scene,
		sizeof(t_scene), CL_MEM_READ_WRITE);
	cl_arg_list_push(renderer->args, renderer->image->color_buffer,
		sizeof(t_color) * renderer->pixel_number, CL_MEM_WRITE_ONLY);
	cl_arg_list_push(renderer->args, NULL,
			sizeof(RT_F4_API) * renderer->pixel_number * RT_SAMPLE_ARRAY_LENGTH,
		CL_MEM_READ_WRITE);
	cl_arg_list_push(renderer->args, &renderer->data.settings,
			sizeof(t_rt_settings), CL_MEM_READ_ONLY);
	cl_arg_list_push(renderer->args, renderer->data.rng_state,
		sizeof(u_long) * renderer->pixel_number, CL_MEM_READ_WRITE);
	cl_builder_set_args(renderer->builder, renderer->args);
}

#ifndef RT_OPEN_CL_DISABLED

t_cl_renderer			*cl_renderer_new(t_gui_image *image)
{
	t_cl_renderer		*new;

	new = rt_malloc(sizeof(t_cl_renderer));
	new->image = image;
	new->pixel_number = image->width * image->height;
	new->builder = cl_builder_new();
	new->args = cl_arg_list_new(new->builder->context, new->builder->queue);
	static_data_init(new);
	static_set_args(new);
	printf("Renderer : Ready\n\n");
	return (new);
}

#else

t_cl_renderer			*cl_renderer_new(t_gui_image *image)
{
	t_cl_renderer		*new;

	new = rt_malloc(sizeof(t_cl_renderer));
	new->image = image;
	new->pixel_number = image->width * image->height;
	new->builder = NULL;
	new->args = NULL;
	static_data_init(new);
	printf("Renderer : Ready\n\n");
	return (new);
}

#endif
