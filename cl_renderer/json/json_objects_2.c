/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   json_objects_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbosmer <sbosmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 19:51:25 by sbosmer           #+#    #+#             */
/*   Updated: 2019/10/08 20:30:10 by sbosmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "json_parse.h"
#include "json_defaults.h"
#include "cl_renderer.h"

void	parse_cylinder(void *data, char *json, jsmntok_t *tokens)
{
	t_obj		box;
	t_scene		*sc;

	sc = ((t_cl_renderer*)data)->data.scene;
	ft_bzero(&box, sizeof(t_obj));
	box.val_v1 = get_vector_in_object(json, tokens, "top");
	box.val_v2 = get_vector_in_object(json, tokens, "bottom");
	box.val_f1 = get_float_in_object(json, tokens, "radius");
	box.val_s1 = get_string_in_object(json, tokens, "material");
	box.val_s2 = get_string_in_object(json, tokens, "name");
	box.val_s3 = get_string_in_object(json, tokens, "texture");
	box.name = (box.val_s2 ? ft_strdup(box.val_s2) : ft_strdup(CYLINDER_NAME));
	box.v1 = (box.val_v1 ? *box.val_v1 : CYLINDER_TOP);
	box.texture = box.val_s3 ? ft_strdup(box.val_s3) : NULL;
	box.v2 = (box.val_v2 ? *box.val_v2 : CYLINDER_BOTTOM);
	box.f1 = (box.val_f1 ? *box.val_f1 : CYLINDER_RADIUS);
	box.material = (box.val_s1 ? decide_material(box.val_s1) :
		CYLINDER_MATERIAL);
	object_build(scene_get_space(sc), object_type_cylinder,
		*(RT_F4_API*)&box.v1, *(RT_F4_API*)&box.v2, box.f1);
	scene_edit_param(sc, -1, scene_param_material, box.material);
	scene_edit_param(sc, -1, scene_param_name, box.name);
	if (box.texture)
		scene_edit_param(sc, -1, scene_param_texture, box.texture);
	free_box(&box);
}

void	parse_box(void *data, char *json, jsmntok_t *tokens)
{
	t_obj		box;
	t_scene		*sc;

	ft_bzero(&box, sizeof(t_obj));
	sc = ((t_cl_renderer*)data)->data.scene;
	box.val_v1 = get_vector_in_object(json, tokens, "position");
	box.val_v2 = get_vector_in_object(json, tokens, "size");
	box.val_s1 = get_string_in_object(json, tokens, "material");
	box.val_s2 = get_string_in_object(json, tokens, "name");
	box.val_s3 = get_string_in_object(json, tokens, "texture");
	box.name = (box.val_s2 ? ft_strdup(box.val_s2) : ft_strdup(BOX_NAME));
	box.v1 = (box.val_v1 ? *box.val_v1 : BOX_POSITION);
	box.texture = box.val_s3 ? ft_strdup(box.val_s3) : NULL;
	box.v2 = (box.val_v2 ? *box.val_v2 : BOX_SIZE);
	box.material = (box.val_s1 ? decide_material(box.val_s1) : BOX_MATERIAL);
	object_build(scene_get_space(sc),
		object_type_box, *(RT_F4_API*)&box.v1, *(RT_F4_API*)&box.v2);
	scene_edit_param(sc, -1, scene_param_material, box.material);
	scene_edit_param(sc, -1, scene_param_name, box.name);
	if (box.texture)
		scene_edit_param(sc, -1, scene_param_texture, box.texture);
	free_box(&box);
}

void	parse_paraboloid(void *data, char *json, jsmntok_t *tokens)
{
	t_obj		box;
	t_scene		*sc;

	sc = ((t_cl_renderer*)data)->data.scene;
	ft_bzero(&box, sizeof(t_obj));
	box.val_v1 = get_vector_in_object(json, tokens, "extremum");
	box.val_v2 = get_vector_in_object(json, tokens, "axis");
	box.val_s1 = get_string_in_object(json, tokens, "material");
	box.val_s2 = get_string_in_object(json, tokens, "name");
	box.val_s3 = get_string_in_object(json, tokens, "texture");
	box.name = (box.val_s2 ? ft_strdup(box.val_s2) : ft_strdup(PARAB_NAME));
	box.val_f1 = get_float_in_object(json, tokens, "radius");
	box.texture = box.val_s3 ? ft_strdup(box.val_s3) : NULL;
	box.v1 = (box.val_v1 ? *box.val_v1 : PARABOLOID_EXTREMUM);
	box.v2 = (box.val_v2 ? *box.val_v2 : PARABOLOID_AXIS);
	box.f1 = (box.val_f1 ? *box.val_f1 : PARABOLOID_RADIUS);
	box.material = (box.val_s1 ? decide_material(box.val_s1) :
		PARABOLOID_MATERIAL);
	object_build(scene_get_space(sc), object_type_paraboloid,
		*(RT_F4_API*)&box.v1, *(RT_F4_API*)&box.v2, box.f1);
	scene_edit_param(sc, -1, scene_param_material, box.material);
	scene_edit_param(sc, -1, scene_param_name, box.name);
	if (box.texture)
		scene_edit_param(sc, -1, scene_param_texture, box.texture);
	free_box(&box);
}

void	parse_moebius(void *data, char *json, jsmntok_t *tokens)
{
	t_obj		box;
	t_scene		*sc;

	sc = ((t_cl_renderer*)data)->data.scene;
	ft_bzero(&box, sizeof(t_obj));
	box.val_v1 = get_vector_in_object(json, tokens, "position");
	box.val_s1 = get_string_in_object(json, tokens, "material");
	box.val_s2 = get_string_in_object(json, tokens, "name");
	box.val_s3 = get_string_in_object(json, tokens, "texture");
	box.name = (box.val_s2 ? ft_strdup(box.val_s2) : ft_strdup(MOEBIUS_NAME));
	box.val_f1 = get_float_in_object(json, tokens, "radius");
	box.texture = box.val_s3 ? ft_strdup(box.val_s3) : NULL;
	box.val_f2 = get_float_in_object(json, tokens, "half width");
	box.v1 = (box.val_v1 ? *box.val_v1 : MOEBIUS_POSITION);
	box.f1 = (box.val_f1 ? *box.val_f1 : MOEBIUS_RADIUS);
	box.f2 = (box.val_f2 ? *box.val_f2 : MOEBIUS_HALFWIDTH);
	box.material = (box.val_s1 ? decide_material(box.val_s1) :
		MOEBIUS_MATERIAL);
	object_build(scene_get_space(sc),
		object_type_moebius, *(RT_F4_API*)&box.v1, box.f1, box.f2);
	scene_edit_param(sc, -1, scene_param_material, box.material);
	scene_edit_param(sc, -1, scene_param_name, box.name);
	if (box.texture)
		scene_edit_param(sc, -1, scene_param_texture, box.texture);
	free_box(&box);
}

void	parse_torus(void *data, char *json, jsmntok_t *tokens)
{
	t_obj		box;

	ft_bzero(&box, sizeof(t_obj));
	box.val_v1 = get_vector_in_object(json, tokens, "position");
	box.val_s1 = get_string_in_object(json, tokens, "material");
	box.val_s2 = get_string_in_object(json, tokens, "name");
	box.val_s3 = get_string_in_object(json, tokens, "texture");
	box.name = (box.val_s2 ? ft_strdup(box.val_s2) : ft_strdup(TORUS_NAME));
	box.val_f1 = get_float_in_object(json, tokens, "radius");
	box.texture = box.val_s3 ? ft_strdup(box.val_s3) : NULL;
	box.val_f2 = get_float_in_object(json, tokens, "width");
	box.v1 = (box.val_v1 ? *box.val_v1 : TORUS_POSITION);
	box.f1 = (box.val_f1 ? *box.val_f1 : TORUS_RADIUS);
	box.f2 = (box.val_f2 ? *box.val_f2 : TORUS_WIDTH);
	box.material = (box.val_s1 ? decide_material(box.val_s1) : TORUS_MATERIAL);
	object_build(scene_get_space(((t_cl_renderer*)data)->data.scene),
		object_type_torus, *(RT_F4_API*)&box.v1, box.f1, box.f2);
	scene_edit_param(((t_cl_renderer*)data)->data.scene, -1,
		scene_param_material, box.material);
	scene_edit_param(((t_cl_renderer*)data)->data.scene, -1,
		scene_param_name, box.name);
	if (box.texture)
		scene_edit_param(((t_cl_renderer*)data)->data.scene, -1,
		scene_param_texture, box.texture);
	free_box(&box);
}
