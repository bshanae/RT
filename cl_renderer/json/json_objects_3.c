/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   json_objects_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbosmer <sbosmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 19:50:40 by sbosmer           #+#    #+#             */
/*   Updated: 2019/10/08 20:50:27 by sbosmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "json_parse.h"
#include "json_defaults.h"
#include "cl_renderer.h"

void	parse_mandelbulb(void *data, char *json, jsmntok_t *tokens)
{
	t_obj		box;
	t_scene		*sc;

	ft_bzero(&box, sizeof(t_obj));
	sc = ((t_cl_renderer*)data)->data.scene;
	box.val_v1 = get_vector_in_object(json, tokens, "position");
	box.val_s1 = get_string_in_object(json, tokens, "material");
	box.val_s2 = get_string_in_object(json, tokens, "name");
	box.val_s3 = get_string_in_object(json, tokens, "texture");
	box.name = (box.val_s2 ? ft_strdup(box.val_s2) : ft_strdup(MANDEL_NAME));
	box.val_i1 = get_int_in_object(json, tokens, "iterations");
	box.texture = box.val_s3 ? ft_strdup(box.val_s3) : NULL;
	box.val_f2 = get_float_in_object(json, tokens, "power");
	box.v1 = (box.val_v1 ? *box.val_v1 : MANDELBULB_POSITION);
	box.i1 = (box.val_i1 && *box.val_i1 >= 1 ? *box.val_i1 :
		MANDELBULB_ITERATIONS);
	box.f2 = (box.val_f2 ? *box.val_f2 : MANDELBULB_POWER);
	box.material = (box.val_s1 ? decide_material(box.val_s1) :
		MANDELBULB_MATERIAL);
	object_build(scene_get_space(sc), 12, *(RT_F4_API*)&box.v1, box.i1, box.f2);
	scene_edit_param(sc, -1, scene_param_material, box.material);
	scene_edit_param(sc, -1, scene_param_name, box.name);
	if (box.texture)
		scene_edit_param(sc, -1, scene_param_texture, box.texture);
	free_box(&box);
}

void	parse_julia(void *data, char *json, jsmntok_t *tokens)
{
	t_obj		box;

	ft_bzero(&box, sizeof(t_obj));
	box.val_v1 = get_vector_in_object(json, tokens, "position");
	box.val_v2 = get_vector_in_object(json, tokens, "value");
	box.val_s1 = get_string_in_object(json, tokens, "material");
	box.val_s2 = get_string_in_object(json, tokens, "name");
	box.val_s3 = get_string_in_object(json, tokens, "texture");
	box.name = (box.val_s2 ? ft_strdup(box.val_s2) : ft_strdup(JULIA_NAME));
	box.val_i1 = get_int_in_object(json, tokens, "iterations");
	box.texture = box.val_s3 ? ft_strdup(box.val_s3) : NULL;
	box.v1 = (box.val_v1 ? *box.val_v1 : JULIA_POSITION);
	box.v2 = (box.val_v2 ? *box.val_v2 : JULIA_VALUE);
	box.i1 = (box.val_i1 && *box.val_i1 >= 1 ? *box.val_i1 : JULIA_ITERATIONS);
	box.material = (box.val_s1 ? decide_material(box.val_s1) : JULIA_MATERIAL);
	object_build(scene_get_space(((t_cl_renderer*)data)->data.scene),
		13, *(RT_F4_API*)&box.v1, box.i1, *(RT_F4_API*)&box.v2, box.f2);
	scene_edit_param(((t_cl_renderer*)data)->data.scene, -1,
		scene_param_material, box.material);
	scene_edit_param(((t_cl_renderer*)data)->data.scene, -1,
		scene_param_name, box.name);
	if (box.texture)
		scene_edit_param(((t_cl_renderer*)data)->data.scene, -1,
			scene_param_texture, box.texture);
	free_box(&box);
}

void	parse_csg(void *data, char *json, jsmntok_t *tokens)
{
	t_obj		box;

	ft_bzero(&box, sizeof(t_obj));
	box.val_s1 = get_string_in_object(json, tokens, "material");
	box.val_s2 = get_string_in_object(json, tokens, "name");
	box.name = (box.val_s2 ? ft_strdup(box.val_s2) : ft_strdup(CSG_NAME));
	box.texture = box.val_s3 ? ft_strdup(box.val_s3) : NULL;
	box.val_s4 = get_string_in_object(json, tokens, "positive");
	box.val_s5 = get_string_in_object(json, tokens, "negative");
	(!(box.val_s4 && box.val_s5) ? free(&box) : 1);
	if (!box.val_s4)
		return ;
	box.material = (box.val_s1 ? decide_material(box.val_s1) :
		EXPLOSION_MATERIAL);
	object_build(scene_get_space(((t_cl_renderer*)data)->data.scene),
		object_type_csg, box.val_s4, box.val_s5);
	scene_edit_param(((t_cl_renderer*)data)->data.scene, -1,
		scene_param_name, box.name);
	scene_edit_param(((t_cl_renderer*)data)->data.scene, -1, scene_param_material, box.material);
	free_box(&box);
}

void	parse_explosion(void *data, char *json, jsmntok_t *tokens)
{
	t_obj		box;
	t_scene		*sc;

	sc = ((t_cl_renderer*)data)->data.scene;
	ft_bzero(&box, sizeof(t_obj));
	box.val_s1 = get_string_in_object(json, tokens, "material");
	box.val_s2 = get_string_in_object(json, tokens, "name");
	box.val_s3 = get_string_in_object(json, tokens, "texture");
	box.name = (box.val_s2 ? ft_strdup(box.val_s2) : ft_strdup(EXPLOSION_NAME));
	box.val_v1 = get_vector_in_object(json, tokens, "position");
	box.texture = box.val_s3 ? ft_strdup(box.val_s3) : NULL;
	box.val_f1 = get_float_in_object(json, tokens, "radius");
	box.val_f2 = get_float_in_object(json, tokens, "noise amplitude");
	box.material = (box.val_s1 ? decide_material(box.val_s1) :
		EXPLOSION_MATERIAL);
	box.v1 = (box.val_v1 ? *box.val_v1 : EXPLOSION_POSITION);
	box.f1 = (box.val_f1 ? *box.val_f1 : EXPLOSION_RADIUS);
	box.f2 = (box.val_f2 ? *box.val_f2 : EXPLOSION_NOISE_AMPLITUDE);
	object_build(scene_get_space(sc),
		object_type_explosion, *(RT_F4_API*)&box.v1, box.f1, box.f2);
	scene_edit_param(sc, -1, scene_param_material, box.material);
	scene_edit_param(sc, -1, scene_param_name, box.name);
	if (box.texture)
		scene_edit_param(sc, -1, scene_param_texture, box.texture);
	free_box(&box);
}

void	parse_perfcube(void *data, char *json, jsmntok_t *tokens)
{
	t_obj		box;

	ft_bzero(&box, sizeof(t_obj));
	box.val_s1 = get_string_in_object(json, tokens, "material");
	box.val_s2 = get_string_in_object(json, tokens, "name");
	box.val_s3 = get_string_in_object(json, tokens, "texture");
	box.name = (box.val_s2 ? ft_strdup(box.val_s2) : ft_strdup(PCUBE_NAME));
	box.val_v1 = get_vector_in_object(json, tokens, "position");
	box.texture = box.val_s3 ? ft_strdup(box.val_s3) : NULL;
	box.val_i1 = get_int_in_object(json, tokens, "iterations");
	box.material = (box.val_s1 ? decide_material(box.val_s1) : PCUBE_MATERIAL);
	box.v1 = (box.val_v1 ? *box.val_v1 : PCUBE_POSITION);
	box.i1 = (box.val_i1 ? *box.val_i1 : PCUBE_ITERATIONS);
	object_build(scene_get_space(((t_cl_renderer*)data)->data.scene),
		object_type_perforated_cube, *(RT_F4_API*)&box.v1, box.i1);
	scene_edit_param(((t_cl_renderer*)data)->data.scene, -1,
		scene_param_material, box.material);
	scene_edit_param(((t_cl_renderer*)data)->data.scene, -1,
		scene_param_name, box.name);
	if (box.texture)
		scene_edit_param(((t_cl_renderer*)data)->data.scene, -1,
			scene_param_texture, box.texture);
	free_box(&box);
}
