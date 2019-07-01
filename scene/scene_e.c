/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_e.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <ashari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 19:12:36 by ashari            #+#    #+#             */
/*   Updated: 2019/07/01 15:10:59 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene_list.h"

t_scene				*scene_e(void)
{
	t_scene			*scene;

	scene = scene_new();
	scene->camera.position = (t_vector3) {0., .5, 8.};
	scene_add_light(scene, light_create(light_ambient, .1));
	scene_add_light(scene,
		light_create(light_point, .5, (t_vector3){2., 0., 10.}));
	scene_add_shape(scene, shape_plane((t_vector3){0., 0., -5.},
		(t_vector3){0., 0., 1}, MATERIAL_RED));
	scene_add_shape(scene, shape_plane((t_vector3){0., 3., 0.},
		(t_vector3){0., 1., 0.}, MATERIAL_RED));
	scene_add_shape(scene, shape_plane((t_vector3){0., -3., 0.},
		(t_vector3){0., 1., 0.}, MATERIAL_RED));
	scene_add_shape(scene, shape_cylinder((t_vector3) {-2., -2., 0.},
		(t_vector3){-2., -2., 0.}, .2, MATERIAL_RED));
	return (scene);
}
