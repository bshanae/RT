/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_f.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <ashari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 19:12:36 by ashari            #+#    #+#             */
/*   Updated: 2019/07/02 13:24:14 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene_list.h"

static void			add_first_floor_planes(t_scene *scene)
{
	scene_add_shape(scene, shape_plane((t_vector3){0., -2., 0.},
		(t_vector3){0., 1., 0}, MATERIAL_GREY));
	scene_add_shape(scene, shape_plane((t_vector3){0., 2.5, 0.},
		(t_vector3){0., -1., 0}, MATERIAL_GREY));
	scene_add_shape(scene, shape_plane((t_vector3){0., 0., -25.},
		(t_vector3){0., 0., 1.}, MATERIAL_GREY));
	scene_add_shape(scene, shape_plane((t_vector3){0., 0., 25.},
		(t_vector3){0., 0., -1.}, MATERIAL_GREY));
	scene_add_shape(scene, shape_plane((t_vector3){-25., 0., 0.},
		(t_vector3){1., 0., 0.}, MATERIAL_GREY));
	scene_add_shape(scene, shape_plane((t_vector3){25., 0., 0.},
		(t_vector3){-1., 0., 0.}, MATERIAL_GREY));
}

static void			add_first_floor_cylinders(t_scene *scene)
{
	scene_add_shape(scene, shape_cylinder((t_vector3) {-2., 0., -5.},
		(t_vector3){-2., 1., -5.}, .4, MATERIAL_GREY));
	scene_add_shape(scene, shape_cylinder((t_vector3) {2., 0., -5.},
		(t_vector3){2., 1., -5.}, .4, MATERIAL_GREY));
	scene_add_shape(scene, shape_cylinder((t_vector3) {-2., 0., 5.},
		(t_vector3){-2., 1., 5.}, .4, MATERIAL_GREY));
	scene_add_shape(scene, shape_cylinder((t_vector3) {2., 0., 5.},
		(t_vector3){2., 1., 5.}, .4, MATERIAL_GREY));
}

static void			add_first_floor_spheres(t_scene *scene)
{
	scene_add_shape(scene,
		shape_sphere((t_vector3) {-2., -2., -5.}, .6, MATERIAL_GREY));
	scene_add_shape(scene,
		shape_sphere((t_vector3) {2., -2., -5.}, .6, MATERIAL_GREY));
	scene_add_shape(scene,
		shape_sphere((t_vector3) {-2., 2.5, -5.}, .6, MATERIAL_GREY));
	scene_add_shape(scene,
		shape_sphere((t_vector3) {2., 2.5, -5.}, .6, MATERIAL_GREY));
	scene_add_shape(scene,
		shape_sphere((t_vector3) {-2., -2., 5.}, .6, MATERIAL_GREY));
	scene_add_shape(scene,
		shape_sphere((t_vector3) {2., -2., 5.}, .6, MATERIAL_GREY));
	scene_add_shape(scene,
		shape_sphere((t_vector3) {-2., 2.5, 5.}, .6, MATERIAL_GREY));
	scene_add_shape(scene,
		shape_sphere((t_vector3) {2., 2.5, 5.}, .6, MATERIAL_GREY));
	scene_add_shape(scene,
		shape_sphere((t_vector3) {-0.8, 0., 0.}, .2, MATERIAL_RED));
	scene_add_shape(scene,
		shape_sphere((t_vector3) {-0.3, 0., 0.}, .2, MATERIAL_GREEN));
	scene_add_shape(scene,
		shape_sphere((t_vector3) {0.2, 0., 0.}, .2, MATERIAL_BLUE));
	scene_add_shape(scene,
		shape_sphere((t_vector3) {0.7, 0., 0.}, .2, MATERIAL_PURPLE));
}

static void			add_second_floor(t_scene *scene)
{
	scene_add_light(scene,
		light_create(light_point, .5, (t_vector3) {-1., 4.7, 5.}));
	scene_add_shape(scene,
		shape_plane((t_vector3){0., 7., 0.},
		(t_vector3){0., -1., 0}, MATERIAL_GREY));
	scene_add_shape(scene,
		shape_sphere((t_vector3) {-2., 7., 5.}, .6, MATERIAL_GREY));
	scene_add_shape(scene,
		shape_sphere((t_vector3) {2., 7., 5.}, .6, MATERIAL_GREY));
	scene_add_shape(scene,
		shape_sphere((t_vector3) {-2., 7., -5.}, .6, MATERIAL_GREY));
	scene_add_shape(scene,
		shape_sphere((t_vector3) {2., 7., -5.}, .6, MATERIAL_GREY));
	scene_add_shape(scene,
		shape_sphere((t_vector3) {0., 3.2, 1.}, .2, MATERIAL_ORANGE_SODA));
	scene_add_shape(scene,
		shape_sphere((t_vector3) {0., 3.7, 1.}, .2, MATERIAL_MIRROR));
	scene_add_shape(scene,
		shape_sphere((t_vector3) {0., 4.2, 1.}, .2, MATERIAL_CRAYOLA));
	scene_add_shape(scene,
		shape_sphere((t_vector3) {0., 4.7, 1.}, .2, MATERIAL_FLAME));
}

t_scene				*scene_f(void)
{
	t_scene			*scene;

	scene = scene_new();
	scene->camera.position = (t_vector3) {0., 0., 20.};
	scene_add_light(scene,
					light_create(light_ambient, .3));
	scene_add_light(scene,
					light_create(light_point, .4, (t_vector3) {0., 1., 0.}));
	scene_add_light(scene,
					light_create(light_point, .7, (t_vector3) {0., 2., 2.}));
	add_first_floor_planes(scene);
	add_first_floor_spheres(scene);
	add_first_floor_cylinders(scene);
	add_second_floor(scene);
	return (scene);
}
