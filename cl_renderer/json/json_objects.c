/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   json_objects.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbosmer <sbosmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 16:06:30 by sbosmer           #+#    #+#             */
/*   Updated: 2019/08/26 18:33:37 by sbosmer          ###   ########.fr       */
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

void	parse_sphere(void *data, char *json, jsmntok_t *tokens)
{
	t_obj			box;
	t_cl_renderer	*r;

	r = (t_cl_renderer*)data;
	box.val_v1 = get_vector_in_object(json, tokens, "position");
	box.val_f = get_float_in_object(json, tokens, "radius");
	box.val_s1 = get_string_in_object(json, tokens, "material");
	box.val_s2 = get_string_in_object(json, tokens, "name");

	box.type = 2;
	box.v1 = (box.val_v1 ? *box.val_v1 : (t_vector3){0.f, 0.f, 0.f});
	box.radius = (box.val_f ? *box.val_f : 1.f);
	box.material = (box.val_s1 ? decide_material(box.val_s1) : MATERIAL_WHITE);
	box.name = (box.val_s2 ? strdup(box.val_s2) : strdup("Unnamed sphere"));

	object_build(scene_get_space(r->data.scene), object_sphere, box.material, *(RT_F4_API*)&box.v1, box.radius, box.name);
//	 printf("Object build(t:%d, p:{%.1f, %.1f, %.1f} r:%.1f, n:%s)\n", box.type, box.v1.x, box.v1.y, box.v1.z, box.radius, box.name);

	free(box.val_v1);
	free(box.val_f);
	free(box.val_s1);
	free(box.val_s2);
	(void)data;
}

void	parse_plane(void *data, char *json, jsmntok_t *tokens)
{
	t_obj		box;
	t_cl_renderer	*r;

	r = (t_cl_renderer*)data;
	box.val_v1 = get_vector_in_object(json, tokens, "position");
	box.val_v2 = get_vector_in_object(json, tokens, "normal");
	box.val_s1 = get_string_in_object(json, tokens, "material");
	box.val_s2 = get_string_in_object(json, tokens, "name");

	box.type = 3;
	box.v1 = (box.val_v1 ? *box.val_v1 : (t_vector3){0.f, 0.f, 0.f});
	box.v2 = (box.val_v2 ? *box.val_v2 : (t_vector3){0.f, 1.f, 0.f});
	box.material = (box.val_s1 ? decide_material(box.val_s1) : MATERIAL_WHITE);
	box.name = (box.val_s2 ? strdup(box.val_s2) : strdup("Unnamed plane"));

	object_build(scene_get_space(r->data.scene), object_plane, box.material, *(RT_F4_API*)&box.v1, *(RT_F4_API*)&box.v2, box.name);
//	 printf("Object build(t:%d, p:{%.1f, %.1f, %.1f}, n:{%.1f, %.1f, %.1f}, n:%s)\n", box.type, box.v1.x, box.v1.y, box.v1.z, box.v2.x, box.v2.y, box.v2.z, box.name);

	free(box.val_v1);
	free(box.val_v2);
	free(box.val_s1);
	free(box.val_s2);
	(void)data;
}

void	parse_cone(void *data, char *json, jsmntok_t *tokens)
{
	t_obj		box;
	t_cl_renderer	*r;

	r = (t_cl_renderer*)data;
	box.val_v1 = get_vector_in_object(json, tokens, "top");
	box.val_v2 = get_vector_in_object(json, tokens, "bottom");
	box.val_f = get_float_in_object(json, tokens, "radius");
	box.val_s1 = get_string_in_object(json, tokens, "material");
	box.val_s2 = get_string_in_object(json, tokens, "name");

	box.type = 4;
	box.v1 = (box.val_v1 ? *box.val_v1 : (t_vector3){0.f, .5f, 0.f});
	box.v2 = (box.val_v2 ? *box.val_v2 : (t_vector3){0.f, -.5f, 0.f});
	box.radius = (box.val_f ? *box.val_f : 1.f);
	box.material = (box.val_s1 ? decide_material(box.val_s1) : MATERIAL_WHITE);
	box.name = (box.val_s2 ? strdup(box.val_s2) : strdup("Unnamed cone"));

	object_build(scene_get_space(r->data.scene), object_cone, box.material, *(RT_F4_API*)&box.v1, *(RT_F4_API*)&box.v2, box.radius, box.name);
//	 printf("Object build(t:%d, t:{%.1f, %.1f, %.1f}, b:{%.1f, %.1f, %.1f}, r:%.1f, n:%s)\n", box.type, box.v1.x, box.v1.y, box.v1.z, box.v2.x, box.v2.y, box.v2.z, box.radius, box.name);

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
	t_cl_renderer	*r;

	r = (t_cl_renderer*)data;
	box.val_v1 = get_vector_in_object(json, tokens, "top");
	box.val_v2 = get_vector_in_object(json, tokens, "bottom");
	box.val_f = get_float_in_object(json, tokens, "radius");
	box.val_s1 = get_string_in_object(json, tokens, "material");
	box.val_s2 = get_string_in_object(json, tokens, "name");

	box.type = 5;
	box.v1 = (box.val_v1 ? *box.val_v1 : (t_vector3){0.f, .5f, 0.f});
	box.v2 = (box.val_v2 ? *box.val_v2 : (t_vector3){0.f, -.5f, 0.f});
	box.radius = (box.val_f ? *box.val_f : 1.f);
	box.material = (box.val_s1 ? decide_material(box.val_s1) : MATERIAL_WHITE);
	box.name = (box.val_s2 ? strdup(box.val_s2) : strdup("Unnamed cylinder"));

	object_build(scene_get_space(r->data.scene), object_cylinder, box.material, *(RT_F4_API*)&box.v1, *(RT_F4_API*)&box.v2, box.radius, box.name);
//	 printf("Object build(t:%d, t:{%.1f, %.1f, %.1f}, b:{%.1f, %.1f, %.1f}, r:%.1f, n:%s)\n", box.type, box.v1.x, box.v1.y, box.v1.z, box.v2.x, box.v2.y, box.v2.z, box.radius, box.name);

	free(box.val_v1);
	free(box.val_v2);
	free(box.val_f);
	free(box.val_s1);
	free(box.val_s2);
	(void)data;
}