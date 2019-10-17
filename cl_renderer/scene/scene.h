/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 15:21:58 by ashari            #+#    #+#             */
/*   Updated: 2019/10/17 13:59:27 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "rt_parameters.h"
# include "scene_point.h"

# include "error_framework.h"
# include "object_interaction.h"
# include "texture.h"

# include <stdlib.h>

typedef enum				e_rt_background
{
	rt_background_none,
	rt_background_one,
	rt_background_interpolation,
	rt_background_end
}							t_rt_background;

CHAR_REF					rt_background_translate(t_rt_background i);

typedef struct				s_scene
{
	t_object				objects[RT_SCENE_CAPACITY];
	int						objects_length;
	int						lights[RT_SCENE_CAPACITY];
	int						lights_length;
	t_texture				texture;
	const t_rt_tracing_mod	*tracing_mod;
	UINT_REF				tracing_mod_mask;
	int						selected_id;
	t_rt_background			background;
	RT_F4_API				background_color;
}							t_scene;

t_scene						*scene_new
							(const t_rt_tracing_mod *mod_ptr,
							UINT_REF mask_ptr);
void						scene_delete(t_scene **scene);

void						scene_func_a(t_scene *scene, int i);

t_object					*scene_find_object_by_id
							(t_scene *scene, int id);
t_object					*scene_find_object_by_name
							(t_scene *scene, CHAR_REF name);
int							scene_find_texture_by_name
							(t_scene *scene, CHAR_REF name);

void						scene_set_id(t_scene *scene);
void						scene_set_name(t_scene *scene);
void						scene_set_pair(t_scene *scene);
void						scene_set_light(t_scene *scene);
void						scene_set_visibility(t_scene *scene);

void						scene_clear(t_scene *scene);
void						scene_update(t_scene *scene);

t_object					*scene_get_space(t_scene *scene);

void						scene_object_remove
							(t_scene *scene, int object_id);
void						scene_object_rename
							(t_scene *scene, int object_id, CHAR_REF name);

int							scene_point_check
							(t_scene *scene, const RT_F4_API *point);

void						scene_select(t_scene *scene, int id);
void						scene_unselect(t_scene *scene);

typedef enum				e_scene_param
{
	scene_param_name,
	scene_param_material,
	scene_param_texture
}							t_scene_param;

void						scene_edit_param(t_scene *scene, int id, ...);

#endif
