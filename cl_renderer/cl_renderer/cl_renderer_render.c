/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cl_renderer_render.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 14:03:16 by ashari            #+#    #+#             */
/*   Updated: 2019/10/17 13:59:27 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cl_renderer.h"

#ifndef RT_OPEN_CL_DISABLED

void				cl_renderer_render(t_cl_renderer *renderer)
{
	t_rt_settings	*settings;

	settings = &renderer->data.settings;
	cl_renderer_queue_pre(renderer);
	if (settings->sample_count > settings->sample_limit)
		return ;
	cl_renderer_queue_in(renderer);
	cl_renderer_queue_post(renderer);
}

#else

void				cl_renderer_render(t_cl_renderer *renderer)
{
	return ;
}

#endif
