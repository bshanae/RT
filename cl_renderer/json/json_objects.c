/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   json_objects.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbosmer <sbosmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 16:06:30 by sbosmer           #+#    #+#             */
/*   Updated: 2019/10/02 16:39:57 by sbosmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "json_parse.h"
#include "json_defaults.h"
#include "cl_renderer.h"

//! Idk what to do w/ these
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
	t_camera	*c;
	r = ((t_cl_renderer*)data)->data.camera;
	// ft_bzero(r->data.camera, sizeof(t_camera));
	c->position = get_vector_in_object(json, tokens, "position", CAMERA_POS);
	c->rotation = get_vector_in_object(json, tokens, "rotation", CAMERA_ROT);
	c->axis_x = CAMERA_AXIS_X;
	c->axis_y = CAMERA_AXIS_Y;
	c->axis_z = CAMERA_AXIS_Z;
	c->forward = CAMERA_AXIS_FORWARD;
	c->forward_backup = CAMERA_AXIS_FORWARDBACKUP;
	c->aperture_size = CAMERA_APERTURESIZE;
	c->focal_length = CAMERA_FOCALLENGTH;
}
//!-------------------------

void	parse_ambient(void *data, char *json, jsmntok_t *tokens)
{
	object_build(scene_get_space(((t_cl_renderer*)data)->data.scene), object_type_light_ambient);
	load_shared(data, json, tokens, (t_default){AMBIENT_NAME, AMBIENT_MATERIAL});
}

void	parse_point(void *data, char *json, jsmntok_t *tokens)
{
	t_vector3	pos;
	
	pos = get_vector_in_object(json, tokens, "position", POINT_POSITION)
	object_build(scene_get_space(((t_cl_renderer*)data)->data.scene), object_type_light_point, *(RT_F4_API*)&pos);
	load_shared(data, json, tokens, (t_default){_NAME, _MATERIAL});
}

void	parse_direct(void *data, char *json, jsmntok_t *tokens)
{
	t_vector3	dir;

	dir = get_vector_in_object(json, tokens, "direction", DIRECT_DIRECTION);
	object_build(scene_get_space(((t_cl_renderer*)data)->data.scene), object_type_light_direct, *(RT_F4_API*)&dir);
	load_shared(data, json, tokens, (t_default){_NAME, _MATERIAL});
}

void	parse_sphere(void *data, char *json, jsmntok_t *tokens)
{
	t_vector3	pos;
	float		r;

	pos = get_vector_in_object(json, tokens, "position", SPHERE_POSITION);
	r = get_float_in_object(json, tokens, "radius", SPHERE_RADIUS);
	object_build(scene_get_space(((t_cl_renderer*)data)->data.scene), object_type_sphere, *(RT_F4_API*)&pos, r);
	load_shared(data, json, tokens, (t_default){_NAME, _MATERIAL});
}

void	parse_plane(void *data, char *json, jsmntok_t *tokens)
{
	t_vector3	pos;
	t_vector3	normal;
	int			limiting;

	pos = get_vector_in_object(json, tokens, "position", PLANE_POSITION);
	normal = get_vector_in_object(json, tokens, "normal", PLANE_NORMAL);
	limiting = get_bool_in_object(json, tokens, "limiting", PLANE_LIMITING);
	object_build(scene_get_space(((t_cl_renderer*)data)->data.scene), object_type_plane, *(RT_F4_API*)&pos, *(RT_F4_API*)&normal, limiting);
	load_shared(data, json, tokens, (t_default){_NAME, _MATERIAL});
}

void	parse_cone(void *data, char *json, jsmntok_t *tokens)
{
	t_vector3	top;
	t_vector3	bot;
	float		r;

	top = get_vector_in_object(json, tokens, "top", CONE_TOP);
	bot = get_vector_in_object(json, tokens, "bottom", CONE_BOTTOM);
	r = get_float_in_object(json, tokens, "radius", CONE_RADIUS);
	object_build(scene_get_space(((t_cl_renderer*)data)->data.scene), object_type_cone, *(RT_F4_API*)&top, *(RT_F4_API*)&bot, r);
	load_shared(data, json, tokens, (t_default){_NAME, _MATERIAL});
}

void	parse_cylinder(void *data, char *json, jsmntok_t *tokens)
{
	t_vector3	top;
	t_vector3	bot;
	float		r;

	top = get_vector_in_object(json, tokens, "top", CYLINDER_TOP);
	bot = get_vector_in_object(json, tokens, "bottom", CYLINDER_BOTTOM);
	r = get_float_in_object(json, tokens, "radius", CYLINDER_RADIUS);
	object_build(scene_get_space(((t_cl_renderer*)data)->data.scene), object_type_cylinder, *(RT_F4_API*)&top, *(RT_F4_API*)&bot, r);
	load_shared(data, json, tokens, (t_default){_NAME, _MATERIAL});
}

void	parse_box(void *data, char *json, jsmntok_t *tokens)
{
	t_vector3	pos;
	t_vector3	size;

	pos = get_vector_in_object(json, tokens, "position", BOX_POSITION);
	size = get_vector_in_object(json, tokens, "size", BOX_SIZE);
	object_build(scene_get_space(((t_cl_renderer*)data)->data.scene), object_type_box, *(RT_F4_API*)&pos, *(RT_F4_API*)&size);
	load_shared(data, json, tokens, (t_default){_NAME, _MATERIAL});
}

void	parse_paraboloid(void *data, char *json, jsmntok_t *tokens)
{
	t_vector3	extremum;
	t_vector3	axis;
	float		r;

	extremum = get_vector_in_object(json, tokens, "extremum", PARABOLOID_EXTREMUM);
	axis = get_vector_in_object(json, tokens, "axis", PARABOLOID_AXIS);
	r = get_float_in_object(json, tokens, "radius", PARABOLOID_RADIUS);
	object_build(scene_get_space(((t_cl_renderer*)data)->data.scene), object_type_paraboloid, *(RT_F4_API*)&extremum, *(RT_F4_API*)&axis, r);
	load_shared(data, json, tokens, (t_default){_NAME, _MATERIAL});
}

void	parse_moebius(void *data, char *json, jsmntok_t *tokens)
{
	t_vector3	pos;
	float		r;
	float		w;

	pos = get_vector_in_object(json, tokens, "position", MOEBIUS_POSITION);
	r = get_float_in_object(json, tokens, "radius", MOEBIUS_RADIUS);
	w = get_float_in_object(json, tokens, "halfwidth", MOEBIUS_HALFWIDTH);
	object_build(scene_get_space(((t_cl_renderer*)data)->data.scene), object_type_moebius, *(RT_F4_API*)&pos, r, w);
	load_shared(data, json, tokens, (t_default){_NAME, _MATERIAL});
}

void	parse_torus(void *data, char *json, jsmntok_t *tokens)
{
	t_vector3	pos;
	float		r;
	float		w;

	pos = get_vector_in_object(json, tokens, "position", TORUS_POSITION);
	r = get_float_in_object(json, tokens, "radius", TORUS_RADIUS);
	w = get_float_in_object(json, tokens, "width", TORUS_WIDTH);
	object_build(scene_get_space(((t_cl_renderer*)data)->data.scene), object_type_torus, *(RT_F4_API*)&pos, r, w);
	load_shared(data, json, tokens, (t_default){_NAME, _MATERIAL});
}

void	parse_mandelbulb(void *data, char *json, jsmntok_t *tokens)
{ 
	t_vector3	pos;
	int			iter;
	float		power;

	pos = get_vector_in_object(json, tokens, "position", MANDELBULB_POSITION);
	iter = get_int_in_object(json, tokens, "iterations", MANDELBULB_ITERATIONS);
	power = get_float_in_object(json, tokens, "power", MANDELBULB_POWER);
	object_build(scene_get_space(((t_cl_renderer*)data)->data.scene), object_type_mandelbulb, *(RT_F4_API*)&pos, iter, power);
	load_shared(data, json, tokens, (t_default){_NAME, _MATERIAL});
}

void	parse_julia(void *data, char *json, jsmntok_t *tokens)
{
	t_vector3	pos;
	t_vector3	val;
	int			iter;

	pos = get_vector_in_object(json, tokens, "position", JULIA_POSITION);
	val = get_vector_in_object(json, tokens, "value", JULIA_VALUE);
	iter = get_int_in_object(json, tokens, "iterations", JULIA_ITERATIONS);
	object_build(scene_get_space(((t_cl_renderer*)data)->data.scene), object_type_julia, *(RT_F4_API*)&pos, iter, *(RT_F4_API*)&val);
	load_shared(data, json, tokens, (t_default){_NAME, _MATERIAL});
}

void	parse_csg(void *data, char *json, jsmntok_t *tokens)
{
	int		pos_id;
	int		neg_id;

	pos_id = get_int_in_object(json, tokens, "positive", CSG_POSITIVE)
	neg_id = get_int_in_object(json, tokens, "negative", CSG_NEGATIVE);
	object_build(scene_get_space(((t_cl_renderer*)data)->data.scene), object_type_csg, pos_id, neg_id);
	load_shared(data, json, tokens, (t_default){_NAME, _MATERIAL});
}

void	parse_explosion(void *data, char *json, jsmntok_t *tokens)
{
	t_vector3	pos;
	float		r;
	float		ampl;

	pos = get_vector_in_object(json, tokens, "position", EXPLOSION_POSITION);
	r = get_float_in_object(json, tokens, "radius", EXPLOSION_RADIUS);
	ampl = get_float_in_object(json, tokens, "noise amplitude", EXPLOSION_NOISE_AMPLITUDE);
	object_build(scene_get_space(((t_cl_renderer*)data)->data.scene), object_type_explosion, *(RT_F4_API*)&pos, r, ampl);
	load_shared(data, json, tokens, (t_default){_NAME, _MATERIAL});
}

void	parse_perfcube(void *data, char *json, jsmntok_t *tokens)
{
	t_vector3	pos;
	int			iter;

	pos = get_vector_in_object(json, tokens, "position", PCUBE_POSITION);
	iter = get_int_in_object(json, tokens, "iterations", PCUBE_ITERATIONS);
	object_build(scene_get_space(((t_cl_renderer*)data)->data.scene), object_type_perforated_cube, *(RT_F4_API*)&pos, iter);
	load_shared(data, json, tokens, (t_default){_NAME, _MATERIAL});
}