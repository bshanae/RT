/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cl_renderer_delete.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 14:02:28 by ashari            #+#    #+#             */
/*   Updated: 2019/10/01 18:09:14 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cl_renderer.h"

void				cl_renderer_delete(t_cl_renderer **renderer)
{
	cl_builder_delete(&(*renderer)->builder);
	cl_arg_list_delete(&(*renderer)->args);
	camera_delete(&(*renderer)->data.camera);
	scene_delete(&(*renderer)->data.scene);
	free((*renderer)->data.rng_state);
	free(*renderer);
	*renderer = NULL;
}
