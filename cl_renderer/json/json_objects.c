/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   json_objects.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbosmer <sbosmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 16:06:30 by sbosmer           #+#    #+#             */
/*   Updated: 2019/08/28 21:14:16 by sbosmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "json_parse.h"
#include "json_defaults.h"
#include "cl_renderer.h"

void	parse_camera(void *data, char *json, jsmntok_t *tokens)
{
	t_obj			box;
	t_cl_renderer	*r;

	r = (t_cl_renderer*)data;
	box.val_v1 = get_vector_in_object(json, tokens, "position");
	box.val_v2 = get_vector_in_object(json, tokens, "rotation");
	if (box.val_v1)
		r->data.camera->position = *(RT_F4_API*)box.val_v1;
	else
		r->data.camera->position = CAMERA_POS;
	if (box.val_v2)
		r->data.camera->rotation = *(RT_F4_API*)box.val_v2;
	else
		r->data.camera->rotation = CAMERA_ROT;
	free(box.val_v1);
	free(box.val_v2);
}

void	parse_ambient(void *data, char *json, jsmntok_t *tokens)
{
	t_obj		box;

	box.val_s1 = get_string_in_object(json, tokens, "material");
	box.val_s2 = get_string_in_object(json, tokens, "name");
	box.material = (box.val_s1 ? decide_material(box.val_s1) : AMBIENT_MATERIAL);
	box.name = (box.val_s2 ? strdup(box.val_s2) : strdup(AMBIENT_NAME));
	object_build(scene_get_space(((t_cl_renderer*)data)->data.scene), object_light_ambient, box.material, box.name);
	free(box.val_s1);
	free(box.val_s2);
}

void	parse_point(void *data, char *json, jsmntok_t *tokens)
{
	t_obj		box;

	box.val_v1 = get_vector_in_object(json, tokens, "position");
	box.val_s1 = get_string_in_object(json, tokens, "material");
	box.val_s2 = get_string_in_object(json, tokens, "name");
	box.v1 = (box.val_v1 ? *box.val_v1 : POINT_POSITION);
	box.material = (box.val_s1 ? decide_material(box.val_s1) : POINT_MATERIAL);
	box.name = (box.val_s2 ? strdup(box.val_s2) : strdup(POINT_NAME));
	object_build(scene_get_space(((t_cl_renderer*)data)->data.scene), object_light_point, box.material, *(RT_F4_API*)&box.v1, box.name);
	free(box.val_v1);
	free(box.val_s1);
	free(box.val_s2);
}

void	parse_direct(void *data, char *json, jsmntok_t *tokens)
{
	t_obj		box;

	box.val_v1 = get_vector_in_object(json, tokens, "direction");
	box.val_s1 = get_string_in_object(json, tokens, "material");
	box.val_s2 = get_string_in_object(json, tokens, "name");
	box.v1 = (box.val_v1 ? *box.val_v1 : DIRECT_DIRECTION);
	box.material = (box.val_s1 ? decide_material(box.val_s1) : DIRECT_MATERIAL);
	box.name = (box.val_s2 ? strdup(box.val_s2) : strdup(DIRECT_NAME));
	object_build(scene_get_space(((t_cl_renderer*)data)->data.scene), object_light_direct, box.material, *(RT_F4_API*)&box.v1, box.name);
	free(box.val_v1);
	free(box.val_s1);
	free(box.val_s2);
}

void	parse_sphere(void *data, char *json, jsmntok_t *tokens)
{
	t_obj			box;

	box.val_v1 = get_vector_in_object(json, tokens, "position");
	box.val_f = get_float_in_object(json, tokens, "radius");
	box.val_s1 = get_string_in_object(json, tokens, "material");
	box.val_s2 = get_string_in_object(json, tokens, "name");
	box.v1 = (box.val_v1 ? *box.val_v1 : SPHERE_POSITION);
	box.radius = (box.val_f ? *box.val_f : SPHERE_RADIUS);
	box.material = (box.val_s1 ? decide_material(box.val_s1) : SPHERE_MATERIAL);
	box.name = (box.val_s2 ? strdup(box.val_s2) : strdup(SPHERE_NAME));
	object_build(scene_get_space(((t_cl_renderer*)data)->data.scene), object_sphere, box.material, *(RT_F4_API*)&box.v1, box.radius, box.name);
	free(box.val_v1);
	free(box.val_f);
	free(box.val_s1);
	free(box.val_s2);
}

void	parse_plane(void *data, char *json, jsmntok_t *tokens)
{
	t_obj		box;

	box.val_v1 = get_vector_in_object(json, tokens, "position");
	box.val_v2 = get_vector_in_object(json, tokens, "normal");
	box.val_s1 = get_string_in_object(json, tokens, "material");
	box.val_s2 = get_string_in_object(json, tokens, "name");
	box.v1 = (box.val_v1 ? *box.val_v1 : PLANE_POSITION);
	box.v2 = (box.val_v2 ? *box.val_v2 : PLANE_NORMAL);
	box.material = (box.val_s1 ? decide_material(box.val_s1) : PLANE_MATERIAL);
	box.name = (box.val_s2 ? strdup(box.val_s2) : strdup(PLANE_NAME));
	object_build(scene_get_space(((t_cl_renderer*)data)->data.scene), object_plane, box.material, *(RT_F4_API*)&box.v1, 0);
	free(box.val_v1);
	free(box.val_v2);
	free(box.val_s1);
	free(box.val_s2);
}

void	parse_cone(void *data, char *json, jsmntok_t *tokens)
{
	t_obj		box;

	box.val_v1 = get_vector_in_object(json, tokens, "top");
	box.val_v2 = get_vector_in_object(json, tokens, "bottom");
	box.val_f = get_float_in_object(json, tokens, "radius");
	box.val_s1 = get_string_in_object(json, tokens, "material");
	box.val_s2 = get_string_in_object(json, tokens, "name");
	box.v1 = (box.val_v1 ? *box.val_v1 : CONE_TOP);
	box.v2 = (box.val_v2 ? *box.val_v2 : CONE_BOTTOM);
	box.radius = (box.val_f ? *box.val_f : CONE_RADIUS);
	box.material = (box.val_s1 ? decide_material(box.val_s1) : CONE_MATERIAL);
	box.name = (box.val_s2 ? strdup(box.val_s2) : strdup(CONE_NAME));
	object_build(scene_get_space(((t_cl_renderer*)data)->data.scene), object_cone, box.material, *(RT_F4_API*)&box.v1, *(RT_F4_API*)&box.v2, box.radius, box.name);
	free(box.val_v1);
	free(box.val_v2);
	free(box.val_f);
	free(box.val_s1);
	free(box.val_s2);
}

void	parse_cylinder(void *data, char *json, jsmntok_t *tokens)
{
	t_obj		box;

	box.val_v1 = get_vector_in_object(json, tokens, "top");
	box.val_v2 = get_vector_in_object(json, tokens, "bottom");
	box.val_f = get_float_in_object(json, tokens, "radius");
	box.val_s1 = get_string_in_object(json, tokens, "material");
	box.val_s2 = get_string_in_object(json, tokens, "name");
	box.v1 = (box.val_v1 ? *box.val_v1 : CYLINDER_TOP);
	box.v2 = (box.val_v2 ? *box.val_v2 : CYLINDER_BOTTOM);
	box.radius = (box.val_f ? *box.val_f : CYLINDER_RADIUS);
	box.material = (box.val_s1 ? decide_material(box.val_s1) : CYLINDER_MATERIAL);
	box.name = (box.val_s2 ? strdup(box.val_s2) : strdup(CYLINDER_NAME));
	object_build(scene_get_space(((t_cl_renderer*)data)->data.scene), object_cylinder, box.material, *(RT_F4_API*)&box.v1, *(RT_F4_API*)&box.v2, box.radius, box.name);
	free(box.val_v1);
	free(box.val_v2);
	free(box.val_f);
	free(box.val_s1);
	free(box.val_s2);
}

void	parse_box(void *data, char *json, jsmntok_t *tokens)
{
	t_obj		box;

	box.val_v1 = get_vector_in_object(json, tokens, "position");
	box.val_v2 = get_vector_in_object(json, tokens, "size");
	box.val_s1 = get_string_in_object(json, tokens, "material");
	box.val_s2 = get_string_in_object(json, tokens, "name");
	box.v1 = (box.val_v1 ? *box.val_v1 : BOX_POSITION);
	box.v2 = (box.val_v2 ? *box.val_v2 : BOX_SIZE);
	box.material = (box.val_s1 ? decide_material(box.val_s1) : BOX_MATERIAL);
	box.name = (box.val_s2 ? strdup(box.val_s2) : strdup(BOX_NAME));
	object_build(scene_get_space(((t_cl_renderer*)data)->data.scene), object_box, box.material, *(RT_F4_API*)&box.v1, *(RT_F4_API*)&box.v2, box.name);
	free(box.val_v1);
	free(box.val_v2);
	free(box.val_s1);
	free(box.val_s2);
}

void	parse_paraboloid(void *data, char *json, jsmntok_t *tokens)
{
	t_obj		box;

	box.val_v1 = get_vector_in_object(json, tokens, "extremum");
	box.val_v2 = get_vector_in_object(json, tokens, "axis");
	box.val_s1 = get_string_in_object(json, tokens, "material");
	box.val_s2 = get_string_in_object(json, tokens, "name");
	box.val_f = get_float_in_object(json, tokens, "radius");
	box.v1 = (box.val_v1 ? *box.val_v1 : PARABOLOID_EXTREMUM);
	box.v2 = (box.val_v2 ? *box.val_v2 : PARABOLOID_AXIS);
	box.radius = (box.val_f ? *box.val_f : PARABOLOID_RADIUS);
	box.material = (box.val_s1 ? decide_material(box.val_s1) : PARABOLOID_MATERIAL);
	box.name = (box.val_s2 ? strdup(box.val_s2) : strdup(PARABOLOID_NAME));
	object_build(scene_get_space(((t_cl_renderer*)data)->data.scene), object_paraboloid, box.material, *(RT_F4_API*)&box.v1, *(RT_F4_API*)&box.v2, box.radius, box.name);
	free(box.val_v1);
	free(box.val_v2);
	free(box.val_s1);
	free(box.val_s2);
	free(box.val_f);
}

void	parse_moebius(void *data, char *json, jsmntok_t *tokens)
{
	t_obj		box;

	box.val_v1 = get_vector_in_object(json, tokens, "position");
	box.val_s1 = get_string_in_object(json, tokens, "material");
	box.val_s2 = get_string_in_object(json, tokens, "name");
	box.val_f = get_float_in_object(json, tokens, "radius");
	box.val_f2 = get_float_in_object(json, tokens, "width");
	box.v1 = (box.val_v1 ? *box.val_v1 : MOEBIUS_POSITION);
	box.radius = (box.val_f ? *box.val_f : MOEBIUS_RADIUS);
	box.width = (box.val_f2 ? *box.val_f2 : MOEBIUS_HALFWIDTH);
	box.material = (box.val_s1 ? decide_material(box.val_s1) : MOEBIUS_MATERIAL);
	box.name = (box.val_s2 ? strdup(box.val_s2) : strdup(MOEBIUS_NAME));
	object_build(scene_get_space(((t_cl_renderer*)data)->data.scene), object_moebius, box.material, *(RT_F4_API*)&box.v1, box.radius, box.width, box.name);
	free(box.val_v1);
	free(box.val_s1);
	free(box.val_s2);
	free(box.val_f);
	free(box.val_f2);
}

void	parse_torus(void *data, char *json, jsmntok_t *tokens)
{
	t_obj		box;

	box.val_v1 = get_vector_in_object(json, tokens, "position");
	box.val_s1 = get_string_in_object(json, tokens, "material");
	box.val_s2 = get_string_in_object(json, tokens, "name");
	box.val_f = get_float_in_object(json, tokens, "radius");
	box.val_f2 = get_float_in_object(json, tokens, "width");
	box.v1 = (box.val_v1 ? *box.val_v1 : TORUS_POSITION);
	box.radius = (box.val_f ? *box.val_f : TORUS_RADIUS);
	box.width = (box.val_f2 ? *box.val_f2 : TORUS_WIDTH);
	box.material = (box.val_s1 ? decide_material(box.val_s1) : TORUS_MATERIAL);
	box.name = (box.val_s2 ? strdup(box.val_s2) : strdup(TORUS_NAME));
	object_build(scene_get_space(((t_cl_renderer*)data)->data.scene), object_torus, box.material, *(RT_F4_API*)&box.v1, box.radius, box.width, box.name);
	free(box.val_v1);
	free(box.val_s1);
	free(box.val_s2);
	free(box.val_f);
	free(box.val_f2);
}

void	parse_mandelbulb(void *data, char *json, jsmntok_t *tokens)
{
	t_obj		box;

	box.val_v1 = get_vector_in_object(json, tokens, "position");
	box.val_s1 = get_string_in_object(json, tokens, "material");
	box.val_s2 = get_string_in_object(json, tokens, "name");
	box.val_f = get_float_in_object(json, tokens, "iterations");
	box.val_f2 = get_float_in_object(json, tokens, "power");
	box.v1 = (box.val_v1 ? *box.val_v1 : MANDELBULB_POSITION);
	box.radius = (box.val_f && *box.val_f >= 1.f ? *box.val_f : MANDELBULB_ITERATIONS);
	box.width = (box.val_f2 ? *box.val_f2 : MANDELBULB_POWER);
	box.material = (box.val_s1 ? decide_material(box.val_s1) : MANDELBULB_MATERIAL);
	box.name = (box.val_s2 ? strdup(box.val_s2) : strdup(MANDELBULB_NAME));
	object_build(scene_get_space(((t_cl_renderer*)data)->data.scene), object_mandelbulb, box.material, *(RT_F4_API*)&box.v1, (int)box.radius, box.width, box.name);
	free(box.val_v1);
	free(box.val_s1);
	free(box.val_s2);
	free(box.val_f);
	free(box.val_f2);
}

void	parse_julia(void *data, char *json, jsmntok_t *tokens)
{
	t_obj		box;

	box.val_v1 = get_vector_in_object(json, tokens, "position");
	box.val_v2 = get_vector_in_object(json, tokens, "value");
	box.val_s1 = get_string_in_object(json, tokens, "material");
	box.val_s2 = get_string_in_object(json, tokens, "name");
	box.val_f = get_float_in_object(json, tokens, "iterations");
	box.v1 = (box.val_v1 ? *box.val_v1 : JULIA_POSITION);
	box.v2 = (box.val_v2 ? *box.val_v2 : JULIA_VALUE);
	box.radius = (box.val_f && *box.val_f >= 1.f ? *box.val_f : JULIA_ITERATIONS);
	box.material = (box.val_s1 ? decide_material(box.val_s1) : JULIA_MATERIAL);
	box.name = (box.val_s2 ? strdup(box.val_s2) : strdup(JULIA_NAME));
	object_build(scene_get_space(((t_cl_renderer*)data)->data.scene), object_julia, box.material, *(RT_F4_API*)&box.v1, (int)box.radius, *(RT_F4_API*)&box.v2, box.width, box.name);
	free(box.val_v1);
	free(box.val_v2);
	free(box.val_s1);
	free(box.val_s2);
	free(box.val_f);
}

void	parse_csg(void *data, char *json, jsmntok_t *tokens)
{
	t_obj		box;

	box.val_s1 = get_string_in_object(json, tokens, "material");
	box.val_s2 = get_string_in_object(json, tokens, "name");
	box.val_f = get_float_in_object(json, tokens, "positive");
	box.val_f2 = get_float_in_object(json, tokens, "negative");
	box.radius = (box.val_f ? *box.val_f : CSG_POSITIVE);
	box.width = (box.val_f2 ? *box.val_f2 : CSG_NEGATIVE);
	box.material = (box.val_s1 ? decide_material(box.val_s1) : CSG_MATERIAL);
	box.name = (box.val_s2 ? strdup(box.val_s2) : strdup(CSG_NAME));
	object_build(scene_get_space(((t_cl_renderer*)data)->data.scene), object_julia, box.material, (int)box.radius, (int)box.width, box.name);
	free(box.val_s1);
	free(box.val_s2);
	free(box.val_f);
	free(box.val_f2);
}