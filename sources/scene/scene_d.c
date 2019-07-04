/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <ashari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 19:12:36 by ashari            #+#    #+#             */
/*   Updated: 2019/07/01 15:05:38 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene_list.h"

t_scene				*scene_d(void)
{
	t_scene			*scene;

	scene = scene_new();
	scene->camera.position = (t_vector3) {0., .5, 10.};
	scene_add_light(scene, light_create(light_ambient, .1));
	scene_add_light(scene,
		light_create(light_point, .5, (t_vector3){0., 3., 10.}));
	scene_add_light(scene,
		light_create(light_point, .7, (t_vector3) {0., 5., 5.}));
	scene_add_shape(scene, shape_plane((t_vector3){0., -1., 0.},
		(t_vector3){0., 1., 0}, MATERIAL_GREY));
	scene_add_shape(scene, shape_cylinder((t_vector3) {-1., 0., -1.},
		(t_vector3){0., 1., -2.}, .4, MATERIAL_RED));
	scene_add_shape(scene, shape_cone((t_vector3) {1., 0., 1.},
		(t_vector3){0., 1., 2.}, 7.2, MATERIAL_GREEN));
	return (scene);
}
