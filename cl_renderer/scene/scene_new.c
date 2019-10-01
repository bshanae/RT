/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 15:22:43 by ashari            #+#    #+#             */
/*   Updated: 2019/10/01 18:09:14 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

t_scene				*scene_new(UINT_REF mod_ptr)
{
	t_scene			*new;

	new = rt_malloc(sizeof(t_scene));
	texture_initialization(&new->texture);
	new->objects_length = 0;
	new->lights_length = 0;
	new->current_mod = mod_ptr;
	new->selected_id = -1;
	new->background = rt_background_interpolation;
	new->background_color = RT_BACKGROUND_COLOR;
	return (new);
}
