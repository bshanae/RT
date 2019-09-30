/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   json_objects.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbosmer <sbosmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 16:06:30 by sbosmer           #+#    #+#             */
/*   Updated: 2019/09/29 18:24:39 by sbosmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "json_parse.h"
#include "json_defaults.h"
#include "cl_renderer.h"

void	parse_settings(void *data, char *json, jsmntok_t *tokens)
{
	t_obj	box;
	box.val_i1 = get_bool_in_object(json, tokens, "use raymarching");
	box.val_i2 = get_bool_in_object(json, tokens, "use double");
	box.i1 = (box.val_i1 ? *box.val_i1 : SETTINGS_USE_RM);
	box.i2 = (box.val_i2 ? *box.val_i2 : SETTINGS_USE_DOUBLE);
}

void	parse_camera(void *data, char *json, jsmntok_t *tokens)
{
	t_obj			box;
	t_cl_renderer	*r;

	r = (t_cl_renderer*)data;
	box.val_v1 = get_vector_in_object(json, tokens, "position");
	box.val_v2 = get_vector_in_object(json, tokens, "rotation");
	if (box.val_v1)
		r->data.camera->position = *(RT_F4_API*)box.val_v1;
	if (box.val_v2)
		r->data.camera->rotation = *(RT_F4_API*)box.val_v2;
	free(box.val_v1);
	free(box.val_v2);
}

void	parse_ambient(void *data, char *json, jsmntok_t *tokens)
{
	t_obj		box;

	box.val_s1 = get_string_in_object(json, tokens, "material");
	box.val_s2 = get_string_in_object(json, tokens, "name");
	box.val_s3 = get_string_in_object(json, tokens, "texture");
	box.name = (box.val_s2 ? strdup(box.val_s2) : strdup(AMBIENT_NAME));
	box.material = (box.val_s1 ? decide_material(box.val_s1) : AMBIENT_MATERIAL);
	box.texture = (box.val_s3 ? strdup(box.val_s3) : AMBIENT_TEXTURE);
	object_build(scene_get_space(((t_cl_renderer*)data)->data.scene), object_type_light_ambient);
	scene_edit_param(((t_cl_renderer*)data)->data.scene, -1, scene_param_material, box.material);
	scene_edit_param(((t_cl_renderer*)data)->data.scene, -1, scene_param_name, box.name);
	scene_edit_param(((t_cl_renderer*)data)->data.scene, -1, scene_param_texture, box.texture);
	free(box.val_s1);
	free(box.val_s2);
	free(box.val_s3);
}

void	parse_point(void *data, char *json, jsmntok_t *tokens)
{
	t_obj		box;

	box.val_v1 = get_vector_in_object(json, tokens, "position");
	box.val_s1 = get_string_in_object(json, tokens, "material");
	box.val_s2 = get_string_in_object(json, tokens, "name");
	box.val_s3 = get_string_in_object(json, tokens, "texture");
	box.name = (box.val_s2 ? strdup(box.val_s2) : strdup(POINT_NAME));
	box.v1 = (box.val_v1 ? *box.val_v1 : POINT_POSITION);
	box.texture = (box.val_s3 ? strdup(box.val_s3) : POINT_TEXTURE);
	box.material = (box.val_s1 ? decide_material(box.val_s1) : POINT_MATERIAL);
	object_build(scene_get_space(((t_cl_renderer*)data)->data.scene), object_type_light_point, *(RT_F4_API*)&box.v1);
	scene_edit_param(((t_cl_renderer*)data)->data.scene, -1, scene_param_material, box.material);
	scene_edit_param(((t_cl_renderer*)data)->data.scene, -1, scene_param_name, box.name);
	scene_edit_param(((t_cl_renderer*)data)->data.scene, -1, scene_param_texture, box.texture);
	free(box.val_v1);
	free(box.val_s2);
	free(box.val_s3);
}

void	parse_direct(void *data, char *json, jsmntok_t *tokens)
{
	t_obj		box;

	box.val_v1 = get_vector_in_object(json, tokens, "direction");
	box.val_s1 = get_string_in_object(json, tokens, "material");
	box.val_s2 = get_string_in_object(json, tokens, "name");
	box.val_s3 = get_string_in_object(json, tokens, "texture");
	box.name = (box.val_s2 ? strdup(box.val_s2) : strdup(DIRECT_NAME));
	box.v1 = (box.val_v1 ? *box.val_v1 : DIRECT_DIRECTION);
	box.texture = (box.val_s3 ? strdup(box.val_s3) : DIRECT_TEXTURE);
	box.material = (box.val_s1 ? decide_material(box.val_s1) : DIRECT_MATERIAL);
	object_build(scene_get_space(((t_cl_renderer*)data)->data.scene), object_type_light_direct, *(RT_F4_API*)&box.v1);
	scene_edit_param(((t_cl_renderer*)data)->data.scene, -1, scene_param_material, box.material);
	scene_edit_param(((t_cl_renderer*)data)->data.scene, -1, scene_param_name, box.name);
	scene_edit_param(((t_cl_renderer*)data)->data.scene, -1, scene_param_texture, box.texture);
	free(box.val_v1);
	free(box.val_s1);
	free(box.val_s2);
	free(box.val_s3);
}

void				parse_sphere(void *data, char *json, jsmntok_t *tokens)
{
	t_obj			box;

	box.val_v1 = get_vector_in_object(json, tokens, "position");
	box.val_f1 = get_float_in_object(json, tokens, "radius");
	box.val_s1 = get_string_in_object(json, tokens, "material");
	box.val_s2 = get_string_in_object(json, tokens, "name");
	box.val_s3 = get_string_in_object(json, tokens, "texture");
	box.name = (box.val_s2 ? strdup(box.val_s2) : strdup(SPHERE_NAME));
	box.v1 = (box.val_v1 ? *box.val_v1 : SPHERE_POSITION);
	box.texture = (box.val_s3 ? strdup(box.val_s3) : SPHERE_TEXTURE);
	box.f1 = (box.val_f1 ? *box.val_f1 : SPHERE_RADIUS);
	box.material = (box.val_s1 ? decide_material(box.val_s1) : SPHERE_MATERIAL);
	object_build(scene_get_space(((t_cl_renderer*)data)->data.scene), object_type_sphere, *(RT_F4_API*)&box.v1, box.f1);
	scene_edit_param(((t_cl_renderer*)data)->data.scene, -1, scene_param_material, box.material);
	scene_edit_param(((t_cl_renderer*)data)->data.scene, -1, scene_param_name, box.name);
	scene_edit_param(((t_cl_renderer*)data)->data.scene, -1, scene_param_texture, box.texture);
	free(box.val_v1);
	free(box.val_f1);
	free(box.val_s1);
	free(box.val_s2);
	free(box.val_s3);
}

void	parse_plane(void *data, char *json, jsmntok_t *tokens)
{
	t_obj		box;

	box.val_v1 = get_vector_in_object(json, tokens, "position");
	box.val_v2 = get_vector_in_object(json, tokens, "normal");
	box.val_s1 = get_string_in_object(json, tokens, "material");
	box.val_s2 = get_string_in_object(json, tokens, "name");
	box.val_s3 = get_string_in_object(json, tokens, "texture");
	box.name = (box.val_s2 ? strdup(box.val_s2) : strdup(PLANE_NAME));
	box.val_i1 = get_bool_in_object(json, tokens, "limiting");
	box.texture = (box.val_s3 ? strdup(box.val_s3) : PLANE_TEXTURE);
	box.v1 = (box.val_v1 ? *box.val_v1 : PLANE_POSITION);
	box.v2 = (box.val_v2 ? *box.val_v2 : PLANE_NORMAL);
	box.i1 = (box.val_i1 ? *box.val_i1 : PLANE_LIMITING);
	box.material = (box.val_s1 ? decide_material(box.val_s1) : PLANE_MATERIAL);
	object_build(scene_get_space(((t_cl_renderer*)data)->data.scene), object_type_plane, *(RT_F4_API*)&box.v1, *(RT_F4_API*)&box.v2, 0);
	scene_edit_param(((t_cl_renderer*)data)->data.scene, -1, scene_param_material, box.material);
	scene_edit_param(((t_cl_renderer*)data)->data.scene, -1, scene_param_name, box.name);
	scene_edit_param(((t_cl_renderer*)data)->data.scene, -1, scene_param_texture, box.texture);
	free(box.val_v1);
	free(box.val_v2);
	free(box.val_s1);
	free(box.val_s2);
	free(box.val_s3);
	free(box.val_i1);
}

void	parse_cone(void *data, char *json, jsmntok_t *tokens)
{
	t_obj		box;

	box.val_v1 = get_vector_in_object(json, tokens, "top");
	box.val_v2 = get_vector_in_object(json, tokens, "bottom");
	box.val_f1 = get_float_in_object(json, tokens, "radius");
	box.val_s1 = get_string_in_object(json, tokens, "material");
	box.val_s2 = get_string_in_object(json, tokens, "name");
	box.val_s3 = get_string_in_object(json, tokens, "texture");
	box.name = (box.val_s2 ? strdup(box.val_s2) : strdup(CONE_NAME));
	box.v1 = (box.val_v1 ? *box.val_v1 : CONE_TOP);
	box.texture = (box.val_s3 ? strdup(box.val_s3) : CONE_TEXTURE);
	box.v2 = (box.val_v2 ? *box.val_v2 : CONE_BOTTOM);
	box.f1 = (box.val_f1 ? *box.val_f1 : CONE_RADIUS);
	box.material = (box.val_s1 ? decide_material(box.val_s1) : CONE_MATERIAL);
	object_build(scene_get_space(((t_cl_renderer*)data)->data.scene), object_type_cone, *(RT_F4_API*)&box.v1, *(RT_F4_API*)&box.v2, box.f1);
	scene_edit_param(((t_cl_renderer*)data)->data.scene, -1, scene_param_material, box.material);
	scene_edit_param(((t_cl_renderer*)data)->data.scene, -1, scene_param_name, box.name);
	scene_edit_param(((t_cl_renderer*)data)->data.scene, -1, scene_param_texture, box.texture);
	free(box.val_v1);
	free(box.val_v2);
	free(box.val_f1);
	free(box.val_s1);
	free(box.val_s2);
	free(box.val_s3);
}

void	parse_cylinder(void *data, char *json, jsmntok_t *tokens)
{
	t_obj		box;

	box.val_v1 = get_vector_in_object(json, tokens, "top");
	box.val_v2 = get_vector_in_object(json, tokens, "bottom");
	box.val_f1 = get_float_in_object(json, tokens, "radius");
	box.val_s1 = get_string_in_object(json, tokens, "material");
	box.val_s2 = get_string_in_object(json, tokens, "name");
	box.val_s3 = get_string_in_object(json, tokens, "texture");
	box.name = (box.val_s2 ? strdup(box.val_s2) : strdup(CYLINDER_NAME));
	box.v1 = (box.val_v1 ? *box.val_v1 : CYLINDER_TOP);
	box.texture = (box.val_s3 ? strdup(box.val_s3) : CYLINDER_TEXTURE);
	box.v2 = (box.val_v2 ? *box.val_v2 : CYLINDER_BOTTOM);
	box.f1 = (box.val_f1 ? *box.val_f1 : CYLINDER_RADIUS);
	box.material = (box.val_s1 ? decide_material(box.val_s1) : CYLINDER_MATERIAL);
	object_build(scene_get_space(((t_cl_renderer*)data)->data.scene), object_type_cylinder, *(RT_F4_API*)&box.v1, *(RT_F4_API*)&box.v2, box.f1);
	scene_edit_param(((t_cl_renderer*)data)->data.scene, -1, scene_param_material, box.material);
	scene_edit_param(((t_cl_renderer*)data)->data.scene, -1, scene_param_name, box.name);
	scene_edit_param(((t_cl_renderer*)data)->data.scene, -1, scene_param_texture, box.texture);
	free(box.val_v1);
	free(box.val_v2);
	free(box.val_f1);
	free(box.val_s1);
	free(box.val_s2);
	free(box.val_s3);
}

void	parse_box(void *data, char *json, jsmntok_t *tokens)
{
	t_obj		box;

	box.val_v1 = get_vector_in_object(json, tokens, "position");
	box.val_v2 = get_vector_in_object(json, tokens, "size");
	box.val_s1 = get_string_in_object(json, tokens, "material");
	box.val_s2 = get_string_in_object(json, tokens, "name");
	box.val_s3 = get_string_in_object(json, tokens, "texture");
	box.name = (box.val_s2 ? strdup(box.val_s2) : strdup(BOX_NAME));
	box.v1 = (box.val_v1 ? *box.val_v1 : BOX_POSITION);
	box.texture = (box.val_s3 ? strdup(box.val_s3) : BOX_TEXTURE);
	box.v2 = (box.val_v2 ? *box.val_v2 : BOX_SIZE);
	box.material = (box.val_s1 ? decide_material(box.val_s1) : BOX_MATERIAL);
	object_build(scene_get_space(((t_cl_renderer*)data)->data.scene), object_type_box, *(RT_F4_API*)&box.v1, *(RT_F4_API*)&box.v2);
	scene_edit_param(((t_cl_renderer*)data)->data.scene, -1, scene_param_material, box.material);
	scene_edit_param(((t_cl_renderer*)data)->data.scene, -1, scene_param_name, box.name);
	scene_edit_param(((t_cl_renderer*)data)->data.scene, -1, scene_param_texture, box.texture);
	free(box.val_v1);
	free(box.val_v2);
	free(box.val_s1);
	free(box.val_s2);
	free(box.val_s3);
}

void	parse_paraboloid(void *data, char *json, jsmntok_t *tokens)
{
	t_obj		box;

	box.val_v1 = get_vector_in_object(json, tokens, "extremum");
	box.val_v2 = get_vector_in_object(json, tokens, "axis");
	box.val_s1 = get_string_in_object(json, tokens, "material");
	box.val_s2 = get_string_in_object(json, tokens, "name");
	box.val_s3 = get_string_in_object(json, tokens, "texture");
	box.name = (box.val_s2 ? strdup(box.val_s2) : strdup(PARABOLOID_NAME));
	box.val_f1 = get_float_in_object(json, tokens, "radius");
	box.texture = (box.val_s3 ? strdup(box.val_s3) : PARABOLOID_TEXTURE);
	box.v1 = (box.val_v1 ? *box.val_v1 : PARABOLOID_EXTREMUM);
	box.v2 = (box.val_v2 ? *box.val_v2 : PARABOLOID_AXIS);
	box.f1 = (box.val_f1 ? *box.val_f1 : PARABOLOID_RADIUS);
	box.material = (box.val_s1 ? decide_material(box.val_s1) : PARABOLOID_MATERIAL);
	object_build(scene_get_space(((t_cl_renderer*)data)->data.scene), object_type_paraboloid, *(RT_F4_API*)&box.v1, *(RT_F4_API*)&box.v2, box.f1);
	scene_edit_param(((t_cl_renderer*)data)->data.scene, -1, scene_param_material, box.material);
	scene_edit_param(((t_cl_renderer*)data)->data.scene, -1, scene_param_name, box.name);
	scene_edit_param(((t_cl_renderer*)data)->data.scene, -1, scene_param_texture, box.texture);
	free(box.val_v1);
	free(box.val_v2);
	free(box.val_s1);
	free(box.val_s2);
	free(box.val_s3);
	free(box.val_f1);
}

void	parse_moebius(void *data, char *json, jsmntok_t *tokens)
{
	t_obj		box;

	box.val_v1 = get_vector_in_object(json, tokens, "position");
	box.val_s1 = get_string_in_object(json, tokens, "material");
	box.val_s2 = get_string_in_object(json, tokens, "name");
	box.val_s3 = get_string_in_object(json, tokens, "texture");
	box.name = (box.val_s2 ? strdup(box.val_s2) : strdup(MOEBIUS_NAME));
	box.val_f1 = get_float_in_object(json, tokens, "radius");
	box.texture = (box.val_s3 ? strdup(box.val_s3) : MOEBIUS_TEXTURE);
	box.val_f2 = get_float_in_object(json, tokens, "width");
	box.v1 = (box.val_v1 ? *box.val_v1 : MOEBIUS_POSITION);
	box.f1 = (box.val_f1 ? *box.val_f1 : MOEBIUS_RADIUS);
	box.f2 = (box.val_f2 ? *box.val_f2 : MOEBIUS_HALFWIDTH);
	box.material = (box.val_s1 ? decide_material(box.val_s1) : MOEBIUS_MATERIAL);
	object_build(scene_get_space(((t_cl_renderer*)data)->data.scene), object_type_moebius, *(RT_F4_API*)&box.v1, box.f1, box.f2);
	scene_edit_param(((t_cl_renderer*)data)->data.scene, -1, scene_param_material, box.material);
	scene_edit_param(((t_cl_renderer*)data)->data.scene, -1, scene_param_name, box.name);
	scene_edit_param(((t_cl_renderer*)data)->data.scene, -1, scene_param_texture, box.texture);
	free(box.val_v1);
	free(box.val_s1);
	free(box.val_s2);
	free(box.val_s3);
	free(box.val_f1);
	free(box.val_f2);
}

void	parse_torus(void *data, char *json, jsmntok_t *tokens)
{
	t_obj		box;

	box.val_v1 = get_vector_in_object(json, tokens, "position");
	box.val_s1 = get_string_in_object(json, tokens, "material");
	box.val_s2 = get_string_in_object(json, tokens, "name");
	box.val_s3 = get_string_in_object(json, tokens, "texture");
	box.name = (box.val_s2 ? strdup(box.val_s2) : strdup(TORUS_NAME));
	box.val_f1 = get_float_in_object(json, tokens, "radius");
	box.texture = (box.val_s3 ? strdup(box.val_s3) : TORUS_TEXTURE);
	box.val_f2 = get_float_in_object(json, tokens, "width");
	box.v1 = (box.val_v1 ? *box.val_v1 : TORUS_POSITION);
	box.f1 = (box.val_f1 ? *box.val_f1 : TORUS_RADIUS);
	box.f2 = (box.val_f2 ? *box.val_f2 : TORUS_WIDTH);
	box.material = (box.val_s1 ? decide_material(box.val_s1) : TORUS_MATERIAL);
	object_build(scene_get_space(((t_cl_renderer*)data)->data.scene), object_type_torus, *(RT_F4_API*)&box.v1, box.f1, box.f2);
	scene_edit_param(((t_cl_renderer*)data)->data.scene, -1, scene_param_material, box.material);
	scene_edit_param(((t_cl_renderer*)data)->data.scene, -1, scene_param_name, box.name);
	scene_edit_param(((t_cl_renderer*)data)->data.scene, -1, scene_param_texture, box.texture);
	free(box.val_v1);
	free(box.val_s1);
	free(box.val_s2);
	free(box.val_s3);
	free(box.val_f1);
	free(box.val_f2);
}

void	parse_mandelbulb(void *data, char *json, jsmntok_t *tokens)
{
	t_obj		box;

	box.val_v1 = get_vector_in_object(json, tokens, "position");
	box.val_s1 = get_string_in_object(json, tokens, "material");
	box.val_s2 = get_string_in_object(json, tokens, "name");
	box.val_s3 = get_string_in_object(json, tokens, "texture");
	box.name = (box.val_s2 ? strdup(box.val_s2) : strdup(MANDELBULB_NAME));
	box.val_f1 = get_float_in_object(json, tokens, "iterations");
	box.texture = (box.val_s3 ? strdup(box.val_s3) : MANDELBULB_TEXTURE);
	box.val_f2 = get_float_in_object(json, tokens, "power");
	box.v1 = (box.val_v1 ? *box.val_v1 : MANDELBULB_POSITION);
	box.f1 = (box.val_f1 && *box.val_f1 >= 1.f ? *box.val_f1 : MANDELBULB_ITERATIONS);
	box.f2 = (box.val_f2 ? *box.val_f2 : MANDELBULB_POWER);
	box.material = (box.val_s1 ? decide_material(box.val_s1) : MANDELBULB_MATERIAL);
	object_build(scene_get_space(((t_cl_renderer*)data)->data.scene), object_type_mandelbulb, *(RT_F4_API*)&box.v1, (int)box.f1, box.f2);
	scene_edit_param(((t_cl_renderer*)data)->data.scene, -1, scene_param_material, box.material);
	scene_edit_param(((t_cl_renderer*)data)->data.scene, -1, scene_param_name, box.name);
	scene_edit_param(((t_cl_renderer*)data)->data.scene, -1, scene_param_texture, box.texture);
	free(box.val_v1);
	free(box.val_s1);
	free(box.val_s2);
	free(box.val_s3);
	free(box.val_f1);
	free(box.val_f2);
}

void	parse_julia(void *data, char *json, jsmntok_t *tokens)
{
	t_obj		box;

	box.val_v1 = get_vector_in_object(json, tokens, "position");
	box.val_v2 = get_vector_in_object(json, tokens, "value");
	box.val_s1 = get_string_in_object(json, tokens, "material");
	box.val_s2 = get_string_in_object(json, tokens, "name");
	box.val_s3 = get_string_in_object(json, tokens, "texture");
	box.name = (box.val_s2 ? strdup(box.val_s2) : strdup(JULIA_NAME));
	box.val_f1 = get_float_in_object(json, tokens, "iterations");
	box.texture = (box.val_s3 ? strdup(box.val_s3) : JULIA_TEXTURE);
	box.v1 = (box.val_v1 ? *box.val_v1 : JULIA_POSITION);
	box.v2 = (box.val_v2 ? *box.val_v2 : JULIA_VALUE);
	box.f1 = (box.val_f1 && *box.val_f1 >= 1.f ? *box.val_f1 : JULIA_ITERATIONS);
	box.material = (box.val_s1 ? decide_material(box.val_s1) : JULIA_MATERIAL);
	object_build(scene_get_space(((t_cl_renderer*)data)->data.scene), object_type_julia, *(RT_F4_API*)&box.v1, (int)box.f1, *(RT_F4_API*)&box.v2, box.f2);
	scene_edit_param(((t_cl_renderer*)data)->data.scene, -1, scene_param_material, box.material);
	scene_edit_param(((t_cl_renderer*)data)->data.scene, -1, scene_param_name, box.name);
	scene_edit_param(((t_cl_renderer*)data)->data.scene, -1, scene_param_texture, box.texture);
	free(box.val_v1);
	free(box.val_v2);
	free(box.val_s1);
	free(box.val_s2);
	free(box.val_s3);
	free(box.val_f1);
}

void	parse_csg(void *data, char *json, jsmntok_t *tokens)
{
	t_obj		box;

	box.val_s1 = get_string_in_object(json, tokens, "material");
	box.val_s2 = get_string_in_object(json, tokens, "name");
	box.val_s3 = get_string_in_object(json, tokens, "texture");
	box.name = (box.val_s2 ? strdup(box.val_s2) : strdup(CSG_NAME));
	box.val_f1 = get_float_in_object(json, tokens, "positive");
	box.texture = (box.val_s3 ? strdup(box.val_s3) : CSG_TEXTURE);
	box.val_f2 = get_float_in_object(json, tokens, "negative");
	box.f1 = (box.val_f1 ? *box.val_f1 : CSG_POSITIVE);
	box.f2 = (box.val_f2 ? *box.val_f2 : CSG_NEGATIVE);
	box.material = (box.val_s1 ? decide_material(box.val_s1) : CSG_MATERIAL);
	object_build(scene_get_space(((t_cl_renderer*)data)->data.scene), object_type_julia, (int)box.f1, (int)box.f2);
	scene_edit_param(((t_cl_renderer*)data)->data.scene, -1, scene_param_material, box.material);
	scene_edit_param(((t_cl_renderer*)data)->data.scene, -1, scene_param_name, box.name);
	scene_edit_param(((t_cl_renderer*)data)->data.scene, -1, scene_param_texture, box.texture);
	free(box.val_s1);
	free(box.val_s2);
	free(box.val_s3);
	free(box.val_f1);
	free(box.val_f2);
}

void	parse_explosion(void *data, char *json, jsmntok_t *tokens)
{
	t_obj		box;

	box.val_s1 = get_string_in_object(json, tokens, "material");
	box.val_s2 = get_string_in_object(json, tokens, "name");
	box.val_s3 = get_string_in_object(json, tokens, "texture");
	box.name = (box.val_s2 ? strdup(box.val_s2) : strdup(EXPLOSION_NAME));
	box.val_v1 = get_vector_in_object(json, tokens, "position");
	box.texture = (box.val_s3 ? strdup(box.val_s3) : EXPLOSION_TEXTURE);
	box.val_f1 = get_float_in_object(json, tokens, "radius");
	box.val_f2 = get_float_in_object(json, tokens, "noise amplitude");
	box.material = (box.val_s1 ? decide_material(box.val_s1) : EXPLOSION_MATERIAL);
	box.v1 = (box.val_v1 ? *box.val_v1 : EXPLOSION_POSITION);
	box.f1 = (box.val_f1 ? *box.val_f1 : EXPLOSION_RADIUS);
	box.f2 = (box.val_f2 ? *box.val_f2 : EXPLOSION_NOISE_AMPLITUDE);
	object_build(scene_get_space(((t_cl_renderer*)data)->data.scene), object_type_explosion, *(RT_F4_API*)&box.v1, box.f1, box.f2);
	scene_edit_param(((t_cl_renderer*)data)->data.scene, -1, scene_param_material, box.material);
	scene_edit_param(((t_cl_renderer*)data)->data.scene, -1, scene_param_name, box.name);
	scene_edit_param(((t_cl_renderer*)data)->data.scene, -1, scene_param_texture, box.texture);
	free(box.val_s1);
	free(box.val_s2);
	free(box.val_s3);
	free(box.val_v1);
	free(box.val_f1);
	free(box.val_f2);
}

void	parse_perfcube(void *data, char *json, jsmntok_t *tokens)
{
	t_obj		box;

	box.val_s1 = get_string_in_object(json, tokens, "material");
	box.val_s2 = get_string_in_object(json, tokens, "name");
	box.val_s3 = get_string_in_object(json, tokens, "texture");
	box.name = (box.val_s2 ? strdup(box.val_s2) : strdup(PCUBE_NAME));
	box.val_v1 = get_vector_in_object(json, tokens, "position");
	box.texture = (box.val_s3 ? strdup(box.val_s3) : PCUBE_TEXTURE);
	box.val_i1 = get_int_in_object(json, tokens, "iterations");
	box.material = (box.val_s1 ? decide_material(box.val_s1) : PCUBE_MATERIAL);
	box.v1 = (box.val_v1 ? *box.val_v1 : PCUBE_POSITION);
	box.i1 = (box.val_i1 ? *box.val_i1 : PCUBE_ITERATIONS);
	object_build(scene_get_space(((t_cl_renderer*)data)->data.scene), object_type_perforated_cube, *(RT_F4_API*)&box.v1, box.i1);
	scene_edit_param(((t_cl_renderer*)data)->data.scene, -1, scene_param_material, box.material);
	scene_edit_param(((t_cl_renderer*)data)->data.scene, -1, scene_param_name, box.name);
	scene_edit_param(((t_cl_renderer*)data)->data.scene, -1, scene_param_texture, box.texture);
	free(box.val_s1);
	free(box.val_s2);
	free(box.val_s3);
	free(box.val_v1);
	free(box.val_i1);
}