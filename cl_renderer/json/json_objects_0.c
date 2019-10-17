/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   json_objects_0.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbosmer <sbosmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 16:06:30 by sbosmer           #+#    #+#             */
/*   Updated: 2019/10/16 20:38:52 by sbosmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "json_parse.h"
#include "json_defaults.h"
#include "cl_renderer.h"

static void		set_settings(const t_obj *box, t_rt_settings *s, int mod)
{
	if (!mod)
	{
		s->rm_step_limit = box->i2;
		s->rm_step_part = box->f1;
		return ;
	}
	s->sample_depth = box->i1;
	s->sample_limit = box->i2;
	s->illumination = box->i3;
	s->illumination_value = box->f1;
}

void			parse_settings(void *data, char *json, jsmntok_t *tokens)
{
	t_rt_settings	*s;
	t_obj			box;

	ft_bzero(&box, sizeof(t_obj));
	s = &((t_cl_renderer*)data)->data.settings;
	box.val_i1 = get_bool_in_object(json, tokens, "rm mod");
	box.val_i2 = get_int_in_object(json, tokens, "rm limit");
	box.val_f1 = get_float_in_object(json, tokens, "rm part");
	box.i1 = (box.val_i1 ? *box.val_i1 : SETTINGS_USE_RM);
	box.i2 = (box.val_i2 ? *box.val_i2 : SETTINGS_STEP_LIMIT);
	box.f1 = (box.val_f1 ? *box.val_f1 : SETTINGS_STEP_PART);
	cl_renderer_change_tracing_mod(data, (box.i1 ? 1 : 0));
	set_settings(&box, s, 0);
	free_box(&box);
	box.val_i1 = get_int_in_object(json, tokens, "pt depth");
	box.val_i2 = get_int_in_object(json, tokens, "pt limit");
	box.val_i3 = get_bool_in_object(json, tokens, "illumination mod");
	box.val_f1 = get_float_in_object(json, tokens, "illumination value");
	box.i1 = (box.val_i1 ? *box.val_i1 : SETTINGS_PT_DEPTH);
	box.i2 = (box.val_i2 ? *box.val_i2 : SETTINGS_PT_SAMPLE_LIMIT);
	box.i3 = (box.val_i3 ? *box.val_i3 : SETTINGS_ILLUMINATION_MOD);
	box.f1 = (box.val_f1 ? *box.val_f1 : SETTINGS_ILLUMINATION_VALUE);
	set_settings(&box, s, 1);
	parse_hack_0(&box, data, json, tokens);
	parse_hack_1(&box, data, json, tokens);
}

void			parse_camera(void *data, char *json, jsmntok_t *tokens)
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

void			parse_ambient(void *data, char *json, jsmntok_t *tokens)
{
	t_obj		box;

	ft_bzero(&box, sizeof(t_obj));
	box.val_s1 = get_string_in_object(json, tokens, "material");
	box.val_s2 = get_string_in_object(json, tokens, "name");
	box.val_s3 = get_string_in_object(json, tokens, "texture");
	box.name = (box.val_s2 ? ft_strdup(box.val_s2) : ft_strdup(AMBIENT_NAME));
	box.material = (box.val_s1 ? decide_material(box.val_s1) :
		AMBIENT_MATERIAL);
	box.texture = box.val_s3 ? ft_strdup(box.val_s3) : NULL;
	object_build(scene_get_space(((t_cl_renderer*)data)->data.scene),
		object_type_light_ambient);
	scene_edit_param(((t_cl_renderer*)data)->data.scene, -1,
		scene_param_material, box.material);
	scene_edit_param(((t_cl_renderer*)data)->data.scene, -1,
		scene_param_name, box.name);
	if (box.texture)
		scene_edit_param(((t_cl_renderer*)data)->data.scene,
			-1, scene_param_texture, box.texture);
	free_box(&box);
}

void			parse_limited(void *data, char *json, jsmntok_t *tokens)
{
	t_obj		box;

	ft_bzero(&box, sizeof(t_obj));
	box.val_s2 = get_string_in_object(json, tokens, "name");
	box.val_s4 = get_string_in_object(json, tokens, "main");
	box.val_s5 = get_string_in_object(json, tokens, "limit");
	box.name = (box.val_s2 ? ft_strdup(box.val_s2) : ft_strdup(""));
	(!(box.val_s4 && box.val_s5) ? free_box(&box) : 1);
	if (!(box.val_s4 && box.val_s5))
		return ;
	object_build(scene_get_space(((t_cl_renderer*)data)->data.scene),
		object_type_limited, box.val_s4, box.val_s5);
	scene_edit_param(((t_cl_renderer*)data)->data.scene, -1,
		scene_param_name, box.name);
	free_box(&box);
}
