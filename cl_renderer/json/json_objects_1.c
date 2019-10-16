/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   json_objects_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbosmer <sbosmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 19:52:05 by sbosmer           #+#    #+#             */
/*   Updated: 2019/10/08 20:21:32 by sbosmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "json_parse.h"
#include "json_defaults.h"
#include "cl_renderer.h"

void	parse_point(void *data, char *json, jsmntok_t *tokens)
{
	t_obj		box;

	ft_bzero(&box, sizeof(t_obj));
	box.val_v1 = get_vector_in_object(json, tokens, "position");
	box.val_s1 = get_string_in_object(json, tokens, "material");
	box.val_s2 = get_string_in_object(json, tokens, "name");
	box.val_s3 = get_string_in_object(json, tokens, "texture");
	box.name = (box.val_s2 ? ft_strdup(box.val_s2) : ft_strdup(POINT_NAME));
	box.v1 = (box.val_v1 ? *box.val_v1 : POINT_POSITION);
	box.texture = box.val_s3 ? ft_strdup(box.val_s3) : NULL;
	box.material = (box.val_s1 ? decide_material(box.val_s1) : POINT_MATERIAL);
	object_build(scene_get_space(((t_cl_renderer*)data)->data.scene),
		object_type_light_point, *(RT_F4_API*)&box.v1);
	scene_edit_param(((t_cl_renderer*)data)->data.scene, -1,
		scene_param_material, box.material);
	scene_edit_param(((t_cl_renderer*)data)->data.scene, -1,
		scene_param_name, box.name);
	if (box.texture)
		scene_edit_param(((t_cl_renderer*)data)->data.scene, -1,
			scene_param_texture, box.texture);
	free_box(&box);
}

void	parse_direct(void *data, char *json, jsmntok_t *tokens)
{
	t_obj		box;

	ft_bzero(&box, sizeof(t_obj));
	box.val_v1 = get_vector_in_object(json, tokens, "direction");
	box.val_s1 = get_string_in_object(json, tokens, "material");
	box.val_s2 = get_string_in_object(json, tokens, "name");
	box.val_s3 = get_string_in_object(json, tokens, "texture");
	box.name = (box.val_s2 ? ft_strdup(box.val_s2) : ft_strdup(DIRECT_NAME));
	box.v1 = (box.val_v1 ? *box.val_v1 : DIRECT_DIRECTION);
	box.texture = box.val_s3 ? ft_strdup(box.val_s3) : NULL;
	box.material = (box.val_s1 ? decide_material(box.val_s1) : DIRECT_MATERIAL);
	object_build(scene_get_space(((t_cl_renderer*)data)->data.scene),
		object_type_light_direct, *(RT_F4_API*)&box.v1);
	scene_edit_param(((t_cl_renderer*)data)->data.scene, -1,
		scene_param_material, box.material);
	scene_edit_param(((t_cl_renderer*)data)->data.scene, -1,
		scene_param_name, box.name);
	if (box.texture)
		scene_edit_param(((t_cl_renderer*)data)->data.scene, -1,
			scene_param_texture, box.texture);
	free_box(&box);
}

void	parse_sphere(void *data, char *json, jsmntok_t *tokens)
{
	t_obj			box;

	ft_bzero(&box, sizeof(t_obj));
	box.val_v1 = get_vector_in_object(json, tokens, "position");
	box.val_f1 = get_float_in_object(json, tokens, "radius");
	box.val_s1 = get_string_in_object(json, tokens, "material");
	box.val_s2 = get_string_in_object(json, tokens, "name");
	box.val_s3 = get_string_in_object(json, tokens, "texture");
	box.name = (box.val_s2 ? ft_strdup(box.val_s2) : ft_strdup(SPHERE_NAME));
	box.v1 = (box.val_v1 ? *box.val_v1 : SPHERE_POSITION);
	box.texture = box.val_s3 ? ft_strdup(box.val_s3) : NULL;
	box.f1 = (box.val_f1 ? *box.val_f1 : SPHERE_RADIUS);
	box.material = (box.val_s1 ? decide_material(box.val_s1) : SPHERE_MATERIAL);
	object_build(scene_get_space(((t_cl_renderer*)data)->data.scene),
		object_type_sphere, *(RT_F4_API*)&box.v1, box.f1);
	scene_edit_param(((t_cl_renderer*)data)->data.scene, -1,
		scene_param_material, box.material);
	scene_edit_param(((t_cl_renderer*)data)->data.scene, -1,
		scene_param_name, box.name);
	if (box.texture)
		scene_edit_param(((t_cl_renderer*)data)->data.scene, -1,
			scene_param_texture, box.texture);
	free_box(&box);
}

void	parse_plane(void *data, char *json, jsmntok_t *tokens)
{
	t_obj		box;

	ft_bzero(&box, sizeof(t_obj));
	box.val_v1 = get_vector_in_object(json, tokens, "position");
	box.val_v2 = get_vector_in_object(json, tokens, "normal");
	box.val_s1 = get_string_in_object(json, tokens, "material");
	box.val_s2 = get_string_in_object(json, tokens, "name");
	box.val_s3 = get_string_in_object(json, tokens, "texture");
	box.name = (box.val_s2 ? ft_strdup(box.val_s2) : ft_strdup(PLANE_NAME));
	box.val_i1 = get_bool_in_object(json, tokens, "limiting");
	box.texture = box.val_s3 ? ft_strdup(box.val_s3) : NULL;
	box.v1 = (box.val_v1 ? *box.val_v1 : PLANE_POSITION);
	box.v2 = (box.val_v2 ? *box.val_v2 : PLANE_NORMAL);
	box.i1 = (box.val_i1 ? *box.val_i1 : PLANE_LIMITING);
	box.material = (box.val_s1 ? decide_material(box.val_s1) : PLANE_MATERIAL);
	object_build(scene_get_space(((t_cl_renderer*)data)->data.scene),
		object_type_plane, *(RT_F4_API*)&box.v1, *(RT_F4_API*)&box.v2, box.i1);
	scene_edit_param(((t_cl_renderer*)data)->data.scene, -1,
		scene_param_material, box.material);
	scene_edit_param(((t_cl_renderer*)data)->data.scene, -1,
		scene_param_name, box.name);
	if (box.texture)
		scene_edit_param(((t_cl_renderer*)data)->data.scene, -1,
			scene_param_texture, box.texture);
	free_box(&box);
}

void	parse_cone(void *data, char *json, jsmntok_t *tokens)
{
	t_obj		box;

	ft_bzero(&box, sizeof(t_obj));
	box.val_v1 = get_vector_in_object(json, tokens, "top");
	box.val_v2 = get_vector_in_object(json, tokens, "bottom");
	box.val_f1 = get_float_in_object(json, tokens, "radius");
	box.val_s1 = get_string_in_object(json, tokens, "material");
	box.val_s2 = get_string_in_object(json, tokens, "name");
	box.val_s3 = get_string_in_object(json, tokens, "texture");
	box.name = (box.val_s2 ? ft_strdup(box.val_s2) : ft_strdup(CONE_NAME));
	box.v1 = (box.val_v1 ? *box.val_v1 : CONE_TOP);
	box.texture = box.val_s3 ? ft_strdup(box.val_s3) : NULL;
	box.v2 = (box.val_v2 ? *box.val_v2 : CONE_BOTTOM);
	box.f1 = (box.val_f1 ? *box.val_f1 : CONE_RADIUS);
	box.material = (box.val_s1 ? decide_material(box.val_s1) : CONE_MATERIAL);
	object_build(scene_get_space(((t_cl_renderer*)data)->data.scene),
		object_type_cone, *(RT_F4_API*)&box.v1, *(RT_F4_API*)&box.v2, box.f1);
	scene_edit_param(((t_cl_renderer*)data)->data.scene, -1,
		scene_param_material, box.material);
	scene_edit_param(((t_cl_renderer*)data)->data.scene, -1,
		scene_param_name, box.name);
	if (box.texture)
		scene_edit_param(((t_cl_renderer*)data)->data.scene, -1,
			scene_param_texture, box.texture);
	free_box(&box);
}
