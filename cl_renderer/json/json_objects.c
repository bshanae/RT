/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   json_objects.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbosmer <sbosmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 16:06:30 by sbosmer           #+#    #+#             */
/*   Updated: 2019/09/04 22:43:38 by sbosmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "json_parse.h"
#include "json_defaults.h"
#include "cl_renderer.h"

void	parse_camera(void *data, char *json, jsmntok_t *tokens)
{
	t_obj			box;
	t_cl_renderer	*r;

	ft_bzero(r->data.camera, sizeof(t_camera));
	r = (t_cl_renderer*)data;
	box.val_v1 = get_vector_in_object(json, tokens, "position");
	box.val_v2 = get_vector_in_object(json, tokens, "rotation");
	r->data.camera->position = (box.val_v1 ? *(RT_F4_API*)box.val_v1 : CAMERA_POS);
	r->data.camera->rotation = (box.val_v2 ? *(RT_F4_API*)box.val_v2 : CAMERA_ROT);
	r->data.camera->axis_x = CAMERA_AXIS_X;
	r->data.camera->axis_y = CAMERA_AXIS_Y;
	r->data.camera->axis_z = CAMERA_AXIS_Z;
	r->data.camera->forward = CAMERA_AXIS_FORWARD;
	r->data.camera->forward_backup = CAMERA_AXIS_FORWARDBACKUP;
	r->data.camera->aperture_size = CAMERA_APERTURESIZE;
	r->data.camera->focal_length = CAMERA_FOCALLENGTH;
	free(box.val_v1);
	free(box.val_v2);
}

void	parse_ambient(void *data, char *json, jsmntok_t *tokens)
{
	t_obj		box;

	box.val_s1 = get_string_in_object(json, tokens, "material");
	box.material = (box.val_s1 ? decide_material(box.val_s1) : AMBIENT_MATERIAL);
	object_build(scene_get_space(((t_cl_renderer*)data)->data.scene), object_type_light_ambient, box.material);
	free(box.val_s1);
}

void	parse_point(void *data, char *json, jsmntok_t *tokens)
{
	t_obj		box;

	box.val_v1 = get_vector_in_object(json, tokens, "position");
	box.val_s1 = get_string_in_object(json, tokens, "material");
	box.v1 = (box.val_v1 ? *box.val_v1 : POINT_POSITION);
	box.material = (box.val_s1 ? decide_material(box.val_s1) : POINT_MATERIAL);
	object_build(scene_get_space(((t_cl_renderer*)data)->data.scene), object_type_light_point, box.material, *(RT_F4_API*)&box.v1);
	free(box.val_v1);
	free(box.val_s1);
}

void	parse_direct(void *data, char *json, jsmntok_t *tokens)
{
	t_obj		box;

	box.val_v1 = get_vector_in_object(json, tokens, "direction");
	box.val_s1 = get_string_in_object(json, tokens, "material");
	box.v1 = (box.val_v1 ? *box.val_v1 : DIRECT_DIRECTION);
	box.material = (box.val_s1 ? decide_material(box.val_s1) : DIRECT_MATERIAL);
	object_build(scene_get_space(((t_cl_renderer*)data)->data.scene), object_type_light_direct, box.material, *(RT_F4_API*)&box.v1);
	free(box.val_v1);
	free(box.val_s1);
	free(box.val_s2);
}

void	parse_sphere(void *data, char *json, jsmntok_t *tokens)
{
	t_obj			box;

	box.val_v1 = get_vector_in_object(json, tokens, "position");
	box.val_f1 = get_float_in_object(json, tokens, "radius");
	box.val_s1 = get_string_in_object(json, tokens, "material");
	box.v1 = (box.val_v1 ? *box.val_v1 : SPHERE_POSITION);
	box.f1 = (box.val_f1 ? *box.val_f1 : SPHERE_RADIUS);
	box.material = (box.val_s1 ? decide_material(box.val_s1) : SPHERE_MATERIAL);
	object_build(scene_get_space(((t_cl_renderer*)data)->data.scene), object_type_sphere, box.material, *(RT_F4_API*)&box.v1, box.f1);
	free(box.val_v1);
	free(box.val_f1);
	free(box.val_s1);
	free(box.val_s2);
}

void	parse_plane(void *data, char *json, jsmntok_t *tokens)
{
	t_obj		box;

	box.val_v1 = get_vector_in_object(json, tokens, "position");
	box.val_v2 = get_vector_in_object(json, tokens, "normal");
	box.val_s1 = get_string_in_object(json, tokens, "material");
	box.val_i1 = get_bool_in_object(json, tokens, "limiting");
	box.v1 = (box.val_v1 ? *box.val_v1 : PLANE_POSITION);
	box.v2 = (box.val_v2 ? *box.val_v2 : PLANE_NORMAL);
	box.i1 = (box.val_i1 ? *box.val_i1 : PLANE_LIMITING);
	box.material = (box.val_s1 ? decide_material(box.val_s1) : PLANE_MATERIAL);
	object_build(scene_get_space(((t_cl_renderer*)data)->data.scene), object_type_plane, box.material, *(RT_F4_API*)&box.v1, 0);
	free(box.val_v1);
	free(box.val_v2);
	free(box.val_s1);
	free(box.val_s2);
	free(box.val_i1);
}

void	parse_cone(void *data, char *json, jsmntok_t *tokens)
{
	t_obj		box;

	box.val_v1 = get_vector_in_object(json, tokens, "top");
	box.val_v2 = get_vector_in_object(json, tokens, "bottom");
	box.val_f1 = get_float_in_object(json, tokens, "radius");
	box.val_s1 = get_string_in_object(json, tokens, "material");
	box.v1 = (box.val_v1 ? *box.val_v1 : CONE_TOP);
	box.v2 = (box.val_v2 ? *box.val_v2 : CONE_BOTTOM);
	box.f1 = (box.val_f1 ? *box.val_f1 : CONE_RADIUS);
	box.material = (box.val_s1 ? decide_material(box.val_s1) : CONE_MATERIAL);
	object_build(scene_get_space(((t_cl_renderer*)data)->data.scene), object_type_cone, box.material, *(RT_F4_API*)&box.v1, *(RT_F4_API*)&box.v2, box.f1);
	free(box.val_v1);
	free(box.val_v2);
	free(box.val_f1);
	free(box.val_s1);
	free(box.val_s2);
}

void	parse_cylinder(void *data, char *json, jsmntok_t *tokens)
{
	t_obj		box;

	box.val_v1 = get_vector_in_object(json, tokens, "top");
	box.val_v2 = get_vector_in_object(json, tokens, "bottom");
	box.val_f1 = get_float_in_object(json, tokens, "radius");
	box.val_s1 = get_string_in_object(json, tokens, "material");
	box.v1 = (box.val_v1 ? *box.val_v1 : CYLINDER_TOP);
	box.v2 = (box.val_v2 ? *box.val_v2 : CYLINDER_BOTTOM);
	box.f1 = (box.val_f1 ? *box.val_f1 : CYLINDER_RADIUS);
	box.material = (box.val_s1 ? decide_material(box.val_s1) : CYLINDER_MATERIAL);
	object_build(scene_get_space(((t_cl_renderer*)data)->data.scene), object_type_cylinder, box.material, *(RT_F4_API*)&box.v1, *(RT_F4_API*)&box.v2, box.f1);
	free(box.val_v1);
	free(box.val_v2);
	free(box.val_f1);
	free(box.val_s1);
	free(box.val_s2);
}

void	parse_box(void *data, char *json, jsmntok_t *tokens)
{
	t_obj		box;

	box.val_v1 = get_vector_in_object(json, tokens, "position");
	box.val_v2 = get_vector_in_object(json, tokens, "size");
	box.val_s1 = get_string_in_object(json, tokens, "material");
	box.v1 = (box.val_v1 ? *box.val_v1 : BOX_POSITION);
	box.v2 = (box.val_v2 ? *box.val_v2 : BOX_SIZE);
	box.material = (box.val_s1 ? decide_material(box.val_s1) : BOX_MATERIAL);
	object_build(scene_get_space(((t_cl_renderer*)data)->data.scene), object_type_box, box.material, *(RT_F4_API*)&box.v1, *(RT_F4_API*)&box.v2);
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
	box.val_f1 = get_float_in_object(json, tokens, "radius");
	box.v1 = (box.val_v1 ? *box.val_v1 : PARABOLOID_EXTREMUM);
	box.v2 = (box.val_v2 ? *box.val_v2 : PARABOLOID_AXIS);
	box.f1 = (box.val_f1 ? *box.val_f1 : PARABOLOID_RADIUS);
	box.material = (box.val_s1 ? decide_material(box.val_s1) : PARABOLOID_MATERIAL);
	object_build(scene_get_space(((t_cl_renderer*)data)->data.scene), object_type_paraboloid, box.material, *(RT_F4_API*)&box.v1, *(RT_F4_API*)&box.v2, box.f1);
	free(box.val_v1);
	free(box.val_v2);
	free(box.val_s1);
	free(box.val_s2);
	free(box.val_f1);
}

void	parse_moebius(void *data, char *json, jsmntok_t *tokens)
{
	t_obj		box;

	box.val_v1 = get_vector_in_object(json, tokens, "position");
	box.val_s1 = get_string_in_object(json, tokens, "material");
	box.val_f1 = get_float_in_object(json, tokens, "radius");
	box.val_f2 = get_float_in_object(json, tokens, "width");
	box.v1 = (box.val_v1 ? *box.val_v1 : MOEBIUS_POSITION);
	box.f1 = (box.val_f1 ? *box.val_f1 : MOEBIUS_RADIUS);
	box.f2 = (box.val_f2 ? *box.val_f2 : MOEBIUS_HALFWIDTH);
	box.material = (box.val_s1 ? decide_material(box.val_s1) : MOEBIUS_MATERIAL);
	object_build(scene_get_space(((t_cl_renderer*)data)->data.scene), object_type_moebius, box.material, *(RT_F4_API*)&box.v1, box.f1, box.f2);
	free(box.val_v1);
	free(box.val_s1);
	free(box.val_s2);
	free(box.val_f1);
	free(box.val_f2);
}

void	parse_torus(void *data, char *json, jsmntok_t *tokens)
{
	t_obj		box;

	box.val_v1 = get_vector_in_object(json, tokens, "position");
	box.val_s1 = get_string_in_object(json, tokens, "material");
	box.val_f1 = get_float_in_object(json, tokens, "radius");
	box.val_f2 = get_float_in_object(json, tokens, "width");
	box.v1 = (box.val_v1 ? *box.val_v1 : TORUS_POSITION);
	box.f1 = (box.val_f1 ? *box.val_f1 : TORUS_RADIUS);
	box.f2 = (box.val_f2 ? *box.val_f2 : TORUS_WIDTH);
	box.material = (box.val_s1 ? decide_material(box.val_s1) : TORUS_MATERIAL);
	object_build(scene_get_space(((t_cl_renderer*)data)->data.scene), object_type_torus, box.material, *(RT_F4_API*)&box.v1, box.f1, box.f2);
	free(box.val_v1);
	free(box.val_s1);
	free(box.val_s2);
	free(box.val_f1);
	free(box.val_f2);
}

void	parse_mandelbulb(void *data, char *json, jsmntok_t *tokens)
{
	t_obj		box;

	box.val_v1 = get_vector_in_object(json, tokens, "position");
	box.val_s1 = get_string_in_object(json, tokens, "material");
	box.val_f1 = get_float_in_object(json, tokens, "iterations");
	box.val_f2 = get_float_in_object(json, tokens, "power");
	box.v1 = (box.val_v1 ? *box.val_v1 : MANDELBULB_POSITION);
	box.f1 = (box.val_f1 && *box.val_f1 >= 1.f ? *box.val_f1 : MANDELBULB_ITERATIONS);
	box.f2 = (box.val_f2 ? *box.val_f2 : MANDELBULB_POWER);
	box.material = (box.val_s1 ? decide_material(box.val_s1) : MANDELBULB_MATERIAL);
	object_build(scene_get_space(((t_cl_renderer*)data)->data.scene), object_type_mandelbulb, box.material, *(RT_F4_API*)&box.v1, (int)box.f1, box.f2);
	free(box.val_v1);
	free(box.val_s1);
	free(box.val_s2);
	free(box.val_f1);
	free(box.val_f2);
}

void	parse_julia(void *data, char *json, jsmntok_t *tokens)
{
	t_obj		box;

	box.val_v1 = get_vector_in_object(json, tokens, "position");
	box.val_v2 = get_vector_in_object(json, tokens, "value");
	box.val_s1 = get_string_in_object(json, tokens, "material");
	box.val_f1 = get_float_in_object(json, tokens, "iterations");
	box.v1 = (box.val_v1 ? *box.val_v1 : JULIA_POSITION);
	box.v2 = (box.val_v2 ? *box.val_v2 : JULIA_VALUE);
	box.f1 = (box.val_f1 && *box.val_f1 >= 1.f ? *box.val_f1 : JULIA_ITERATIONS);
	box.material = (box.val_s1 ? decide_material(box.val_s1) : JULIA_MATERIAL);
	object_build(scene_get_space(((t_cl_renderer*)data)->data.scene), object_type_julia, box.material, *(RT_F4_API*)&box.v1, (int)box.f1, *(RT_F4_API*)&box.v2, box.f2);
	free(box.val_v1);
	free(box.val_v2);
	free(box.val_s1);
	free(box.val_s2);
	free(box.val_f1);
}

void	parse_csg(void *data, char *json, jsmntok_t *tokens)
{
	t_obj		box;

	box.val_s1 = get_string_in_object(json, tokens, "material");
	box.val_f1 = get_float_in_object(json, tokens, "positive");
	box.val_f2 = get_float_in_object(json, tokens, "negative");
	box.f1 = (box.val_f1 ? *box.val_f1 : CSG_POSITIVE);
	box.f2 = (box.val_f2 ? *box.val_f2 : CSG_NEGATIVE);
	box.material = (box.val_s1 ? decide_material(box.val_s1) : CSG_MATERIAL);
	object_build(scene_get_space(((t_cl_renderer*)data)->data.scene), object_type_julia, box.material, (int)box.f1, (int)box.f2);
	free(box.val_s1);
	free(box.val_s2);
	free(box.val_f1);
	free(box.val_f2);
}