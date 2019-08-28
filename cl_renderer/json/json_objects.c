/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   json_objects.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbosmer <sbosmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 16:06:30 by sbosmer           #+#    #+#             */
/*   Updated: 2019/08/28 20:15:34 by sbosmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "json_parse.h"
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
	if (box.val_v2)
		r->data.camera->rotation = *(RT_F4_API*)box.val_v2;
	free(box.val_v1);
	free(box.val_v2);
	(void)data;
}

void	parse_ambient(void *data, char *json, jsmntok_t *tokens)
{
	t_obj		box;

	box.val_s1 = get_string_in_object(json, tokens, "material");
	box.val_s2 = get_string_in_object(json, tokens, "name");
	box.material = (box.val_s1 ? decide_material(box.val_s1) : MATERIAL_WHITE);
	box.name = (box.val_s2 ? strdup(box.val_s2) : strdup("Ambient light"));
	object_build(scene_get_space(((t_cl_renderer*)data)->data.scene), object_light_ambient, box.material, box.name);
	free(box.val_s1);
	free(box.val_s2);
	(void)data;
}

void	parse_point(void *data, char *json, jsmntok_t *tokens)
{
	t_obj		box;

	box.val_v1 = get_vector_in_object(json, tokens, "position");
	box.val_s1 = get_string_in_object(json, tokens, "material");
	box.val_s2 = get_string_in_object(json, tokens, "name");
	box.v1 = (box.val_v1 ? *box.val_v1 : (t_vector3){0.f, 0.f, 0.f});
	box.material = (box.val_s1 ? decide_material(box.val_s1) : MATERIAL_WHITE);
	box.name = (box.val_s2 ? strdup(box.val_s2) : strdup("Point light"));
	object_build(scene_get_space(((t_cl_renderer*)data)->data.scene), object_light_point, box.material, *(RT_F4_API*)&box.v1, box.name);
	free(box.val_v1);
	free(box.val_s1);
	free(box.val_s2);
	(void)data;
}

void	parse_direct(void *data, char *json, jsmntok_t *tokens)
{
	t_obj		box;

	box.val_v1 = get_vector_in_object(json, tokens, "direction");
	box.val_s1 = get_string_in_object(json, tokens, "material");
	box.val_s2 = get_string_in_object(json, tokens, "name");
	box.v1 = (box.val_v1 ? *box.val_v1 : (t_vector3){0.f, -1.f, 0.f});
	box.material = (box.val_s1 ? decide_material(box.val_s1) : MATERIAL_WHITE);
	box.name = (box.val_s2 ? strdup(box.val_s2) : strdup("Direct light"));
	object_build(scene_get_space(((t_cl_renderer*)data)->data.scene), object_light_direct, box.material, *(RT_F4_API*)&box.v1, box.name);
	free(box.val_v1);
	free(box.val_s1);
	free(box.val_s2);
	(void)data;
}

void	parse_sphere(void *data, char *json, jsmntok_t *tokens)
{
	t_obj			box;

	box.val_v1 = get_vector_in_object(json, tokens, "position");
	box.val_f = get_float_in_object(json, tokens, "radius");
	box.val_s1 = get_string_in_object(json, tokens, "material");
	box.val_s2 = get_string_in_object(json, tokens, "name");
	box.v1 = (box.val_v1 ? *box.val_v1 : (t_vector3){0.f, 0.f, 0.f});
	box.radius = (box.val_f ? *box.val_f : 1.f);
	box.material = (box.val_s1 ? decide_material(box.val_s1) : MATERIAL_WHITE);
	box.name = (box.val_s2 ? strdup(box.val_s2) : strdup("Sphere"));
	object_build(scene_get_space(((t_cl_renderer*)data)->data.scene), object_sphere, box.material, *(RT_F4_API*)&box.v1, box.radius, box.name);
	free(box.val_v1);
	free(box.val_f);
	free(box.val_s1);
	free(box.val_s2);
	(void)data;
}

void	parse_plane(void *data, char *json, jsmntok_t *tokens)
{
	t_obj		box;

	box.val_v1 = get_vector_in_object(json, tokens, "position");
	box.val_v2 = get_vector_in_object(json, tokens, "normal");
	box.val_s1 = get_string_in_object(json, tokens, "material");
	box.val_s2 = get_string_in_object(json, tokens, "name");
	box.v1 = (box.val_v1 ? *box.val_v1 : (t_vector3){0.f, 0.f, 0.f});
	box.v2 = (box.val_v2 ? *box.val_v2 : (t_vector3){0.f, 1.f, 0.f});
	box.material = (box.val_s1 ? decide_material(box.val_s1) : MATERIAL_WHITE);
	box.name = (box.val_s2 ? strdup(box.val_s2) : strdup("Plane"));
	object_build(scene_get_space(((t_cl_renderer*)data)->data.scene), object_plane, box.material, *(RT_F4_API*)&box.v1, *(RT_F4_API*)&box.v2, box.name);
	free(box.val_v1);
	free(box.val_v2);
	free(box.val_s1);
	free(box.val_s2);
	(void)data;
}

void	parse_cone(void *data, char *json, jsmntok_t *tokens)
{
	t_obj		box;

	box.val_v1 = get_vector_in_object(json, tokens, "top");
	box.val_v2 = get_vector_in_object(json, tokens, "bottom");
	box.val_f = get_float_in_object(json, tokens, "radius");
	box.val_s1 = get_string_in_object(json, tokens, "material");
	box.val_s2 = get_string_in_object(json, tokens, "name");
	box.v1 = (box.val_v1 ? *box.val_v1 : (t_vector3){0.f, .5f, 0.f});
	box.v2 = (box.val_v2 ? *box.val_v2 : (t_vector3){0.f, -.5f, 0.f});
	box.radius = (box.val_f ? *box.val_f : 1.f);
	box.material = (box.val_s1 ? decide_material(box.val_s1) : MATERIAL_WHITE);
	box.name = (box.val_s2 ? strdup(box.val_s2) : strdup("Cone"));
	object_build(scene_get_space(((t_cl_renderer*)data)->data.scene), object_cone, box.material, *(RT_F4_API*)&box.v1, *(RT_F4_API*)&box.v2, box.radius, box.name);
	free(box.val_v1);
	free(box.val_v2);
	free(box.val_f);
	free(box.val_s1);
	free(box.val_s2);
	(void)data;
}

void	parse_cylinder(void *data, char *json, jsmntok_t *tokens)
{
	t_obj		box;

	box.val_v1 = get_vector_in_object(json, tokens, "top");
	box.val_v2 = get_vector_in_object(json, tokens, "bottom");
	box.val_f = get_float_in_object(json, tokens, "radius");
	box.val_s1 = get_string_in_object(json, tokens, "material");
	box.val_s2 = get_string_in_object(json, tokens, "name");
	box.v1 = (box.val_v1 ? *box.val_v1 : (t_vector3){0.f, .5f, 0.f});
	box.v2 = (box.val_v2 ? *box.val_v2 : (t_vector3){0.f, -.5f, 0.f});
	box.radius = (box.val_f ? *box.val_f : 1.f);
	box.material = (box.val_s1 ? decide_material(box.val_s1) : MATERIAL_WHITE);
	box.name = (box.val_s2 ? strdup(box.val_s2) : strdup("Cylinder"));
	object_build(scene_get_space(((t_cl_renderer*)data)->data.scene), object_cylinder, box.material, *(RT_F4_API*)&box.v1, *(RT_F4_API*)&box.v2, box.radius, box.name);
	free(box.val_v1);
	free(box.val_v2);
	free(box.val_f);
	free(box.val_s1);
	free(box.val_s2);
	(void)data;
}

void	parse_box(void *data, char *json, jsmntok_t *tokens)
{
	t_obj		box;

	box.val_v1 = get_vector_in_object(json, tokens, "position");
	box.val_v2 = get_vector_in_object(json, tokens, "size");
	box.val_s1 = get_string_in_object(json, tokens, "material");
	box.val_s2 = get_string_in_object(json, tokens, "name");
	box.v1 = (box.val_v1 ? *box.val_v1 : (t_vector3){0.f, 0.f, 0.f});
	box.v2 = (box.val_v2 ? *box.val_v2 : (t_vector3){1.f, 1.f, 1.f});
	box.radius = (box.val_f ? *box.val_f : 1.f);
	box.material = (box.val_s1 ? decide_material(box.val_s1) : MATERIAL_WHITE);
	box.name = (box.val_s2 ? strdup(box.val_s2) : strdup("Box"));
	object_build(scene_get_space(((t_cl_renderer*)data)->data.scene), object_box, box.material, *(RT_F4_API*)&box.v1, *(RT_F4_API*)&box.v2, box.name);
	free(box.val_v1);
	free(box.val_v2);
	free(box.val_s1);
	free(box.val_s2);
	(void)data;
}

void	parse_paraboloid(void *data, char *json, jsmntok_t *tokens)
{
	t_obj		box;

	box.val_v1 = get_vector_in_object(json, tokens, "extremum");
	box.val_v2 = get_vector_in_object(json, tokens, "axis");
	box.val_s1 = get_string_in_object(json, tokens, "material");
	box.val_s2 = get_string_in_object(json, tokens, "name");
	box.val_f = get_float_in_object(json, tokens, "radius");
	box.v1 = (box.val_v1 ? *box.val_v1 : (t_vector3){1.f, 0.f, 0.f});
	box.v2 = (box.val_v2 ? *box.val_v2 : (t_vector3){0.f, 1.f, 0.f});
	box.radius = (box.val_f ? *box.val_f : 1.f);
	box.material = (box.val_s1 ? decide_material(box.val_s1) : MATERIAL_WHITE);
	box.name = (box.val_s2 ? strdup(box.val_s2) : strdup("Paraboloid"));
	object_build(scene_get_space(((t_cl_renderer*)data)->data.scene), object_paraboloid, box.material, *(RT_F4_API*)&box.v1, *(RT_F4_API*)&box.v2, box.radius, box.name);
	free(box.val_v1);
	free(box.val_v2);
	free(box.val_s1);
	free(box.val_s2);
	free(box.val_f);
	(void)data;
}

void	parse_moebius(void *data, char *json, jsmntok_t *tokens)
{
	t_obj		box;

	box.val_v1 = get_vector_in_object(json, tokens, "position");
	box.val_s1 = get_string_in_object(json, tokens, "material");
	box.val_s2 = get_string_in_object(json, tokens, "name");
	box.val_f = get_float_in_object(json, tokens, "radius");
	box.val_f2 = get_float_in_object(json, tokens, "width");
	box.v1 = (box.val_v1 ? *box.val_v1 : (t_vector3){0.f, 0.f, 0.f});
	box.radius = (box.val_f ? *box.val_f : 1.f);
	box.width = (box.val_f2 ? *box.val_f2 : 1.f);
	box.material = (box.val_s1 ? decide_material(box.val_s1) : MATERIAL_WHITE);
	box.name = (box.val_s2 ? strdup(box.val_s2) : strdup("Moebius strip"));
	object_build(scene_get_space(((t_cl_renderer*)data)->data.scene), object_moebius, box.material, *(RT_F4_API*)&box.v1, box.radius, box.width, box.name);
	free(box.val_v1);
	free(box.val_s1);
	free(box.val_s2);
	free(box.val_f);
	free(box.val_f2);
	(void)data;
}

void	parse_torus(void *data, char *json, jsmntok_t *tokens)
{
	t_obj		box;

	box.val_v1 = get_vector_in_object(json, tokens, "position");
	box.val_s1 = get_string_in_object(json, tokens, "material");
	box.val_s2 = get_string_in_object(json, tokens, "name");
	box.val_f = get_float_in_object(json, tokens, "radius");
	box.val_f2 = get_float_in_object(json, tokens, "width");
	box.v1 = (box.val_v1 ? *box.val_v1 : (t_vector3){0.f, 0.f, 0.f});
	box.radius = (box.val_f ? *box.val_f : 1.f);
	box.width = (box.val_f2 ? *box.val_f2 : 1.f);
	box.material = (box.val_s1 ? decide_material(box.val_s1) : MATERIAL_WHITE);
	box.name = (box.val_s2 ? strdup(box.val_s2) : strdup("Torus"));
	object_build(scene_get_space(((t_cl_renderer*)data)->data.scene), object_torus, box.material, *(RT_F4_API*)&box.v1, box.radius, box.width, box.name);
	free(box.val_v1);
	free(box.val_s1);
	free(box.val_s2);
	free(box.val_f);
	free(box.val_f2);
	(void)data;
}

void	parse_mandelbulb(void *data, char *json, jsmntok_t *tokens)
{
	t_obj		box;

	box.val_v1 = get_vector_in_object(json, tokens, "position");
	box.val_s1 = get_string_in_object(json, tokens, "material");
	box.val_s2 = get_string_in_object(json, tokens, "name");
	box.val_f = get_float_in_object(json, tokens, "iterations");
	box.val_f2 = get_float_in_object(json, tokens, "power");
	box.v1 = (box.val_v1 ? *box.val_v1 : (t_vector3){0.f, 0.f, 0.f});
	box.radius = (box.val_f && *box.val_f >= 1.f ? *box.val_f : 1.f);
	box.width = (box.val_f2 ? *box.val_f2 : 1.f);
	box.material = (box.val_s1 ? decide_material(box.val_s1) : MATERIAL_WHITE);
	box.name = (box.val_s2 ? strdup(box.val_s2) : strdup("Mandelbulb"));
	object_build(scene_get_space(((t_cl_renderer*)data)->data.scene), object_mandelbulb, box.material, *(RT_F4_API*)&box.v1, (int)box.radius, box.width, box.name);
	free(box.val_v1);
	free(box.val_s1);
	free(box.val_s2);
	free(box.val_f);
	free(box.val_f2);
	(void)data;
}

void	parse_julia(void *data, char *json, jsmntok_t *tokens)
{
	t_obj		box;

	box.val_v1 = get_vector_in_object(json, tokens, "position");
	box.val_v2 = get_vector_in_object(json, tokens, "value");
	box.val_s1 = get_string_in_object(json, tokens, "material");
	box.val_s2 = get_string_in_object(json, tokens, "name");
	box.val_f = get_float_in_object(json, tokens, "iterations");
	box.v1 = (box.val_v1 ? *box.val_v1 : (t_vector3){0.f, 0.f, 0.f});
	box.v2 = (box.val_v2 ? *box.val_v2 : (t_vector3){1.f, 1.f, 1.f});
	box.radius = (box.val_f && *box.val_f >= 1.f ? *box.val_f : 1.f);
	box.material = (box.val_s1 ? decide_material(box.val_s1) : MATERIAL_WHITE);
	box.name = (box.val_s2 ? strdup(box.val_s2) : strdup("Julia"));
	object_build(scene_get_space(((t_cl_renderer*)data)->data.scene), object_julia, box.material, *(RT_F4_API*)&box.v1, (int)box.radius, *(RT_F4_API*)&box.v2, box.width, box.name);
	free(box.val_v1);
	free(box.val_v2);
	free(box.val_s1);
	free(box.val_s2);
	free(box.val_f);
	(void)data;
}

void	parse_csg(void *data, char *json, jsmntok_t)
{
	t_obj		box;

	box.val_s1 = get_string_in_object(json, tokens, "material");
	box.val_s2 = get_string_in_object(json, tokens, "name");
	box.val_f = get_float_in_object(json, tokens, "positive");
	box.val_f2 = get_float_in_object(json, tokens, "negative");
	box.radius = (box.val_f ? *box.val_f : 1.f);
	box.width = (box.val_f2 ? *box.val_f2 : 1.f);
	box.material = (box.val_s1 ? decide_material(box.val_s1) : MATERIAL_WHITE);
	box.name = (box.val_s2 ? strdup(box.val_s2) : strdup("CSG"));
	object_build(scene_get_space(((t_cl_renderer*)data)->data.scene), object_julia, box.material, (int)box.radius, (int)box.width, box.name);
	free(box.val_s1);
	free(box.val_s2);
	free(box.val_f);
	free(box.val_f2);
	(void)data;
}