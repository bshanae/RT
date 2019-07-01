/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 14:49:48 by bshanae           #+#    #+#             */
/*   Updated: 2019/07/01 14:58:55 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene_list.h"

t_scene				*scene_b(void)
{
	t_scene			*scene;
	int 			i;

	scene = scene_new();
	scene->camera.position = (t_vector3) {0., .5, 8.};
	scene_add_light(scene,
		light_create(light_ambient, .1));
	scene_add_light(scene,
		light_create(light_point, .3, (t_vector3){2., 0., 10.}));
	scene_add_light(scene,
		light_create(light_point, .7, (t_vector3) {0., 5., 5.}));
	i = -5;
	while (i < 5)
	{
		scene_add_shape(scene, shape_cylinder((t_vector3) {(float)i, 0., 1.},
			(t_vector3){(float)i, 1., 0.}, .2, MATERIAL_RED));
		i++;
	}
	return (scene);
}
