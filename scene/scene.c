/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <ashari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 19:12:45 by ashari            #+#    #+#             */
/*   Updated: 2019/07/02 11:17:32 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

t_scene				*scene_new(void)
{
	t_scene			*new;

	if (!(new = (t_scene *)malloc(sizeof(t_scene))))
		exit(21);
	new->camera = camera_build(WINDOW_WIDTH / (tan((M_PI / 3.) / 2.)));
	new->background = SCENE_DEF_BACKGROUND;
	new->lights_length = 0;
	new->shapes_length = 0;
	return (new);
}

void				scene_delete(t_scene **me)
{
	free(*me);
	*me = NULL;
}

void				scene_add_light(t_scene *me, t_light light)
{
	if (me->lights_length < SCENE_LIGHT_CAPACITY)
		me->lights[me->lights_length++] = light;
}

void				scene_add_shape(t_scene *me, t_shape shape)
{
	if (me->shapes_length < SCENE_SHAPE_CAPACITY)
		me->shapes[me->shapes_length++] = shape;
}
