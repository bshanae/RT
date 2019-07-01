/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_control.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <ashari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 19:12:14 by ashari            #+#    #+#             */
/*   Updated: 2019/07/01 12:05:47 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int					rt_ctrl_camera_move(t_rt *rt, int key)
{
	t_camera		*camera;

	camera = &(*rt->scenes.current)->camera;
	if (key == KEY_W)
		vector3_s_sub_eq(&camera->position,
		vector3_s_mul(camera->axis_z, RT_CAMERA_POS_STEP));
	else if (key == KEY_S)
		vector3_s_add_eq(&camera->position,
		vector3_s_mul(camera->axis_z, RT_CAMERA_POS_STEP));
	else if (key == KEY_A)
		vector3_s_sub_eq(&camera->position,
		vector3_s_mul(camera->axis_x, RT_CAMERA_POS_STEP));
	else if (key == KEY_D)
		vector3_s_add_eq(&camera->position,
		vector3_s_mul(camera->axis_x, RT_CAMERA_POS_STEP));
	else if (key == KEY_E)
		camera->position.y -= RT_CAMERA_POS_STEP;
	else if (key == KEY_Q)
		camera->position.y += RT_CAMERA_POS_STEP;
	else
		return (0);
	return (1);
}

int					rt_ctrl_camera_rotate(t_rt *rt, int key)
{
	t_camera		*camera;

	camera = &(*rt->scenes.current)->camera;
	if (key == KEY_LEFT_1)
		camera->angles.y += RT_CAMERA_DIR_STEP;
	else if (key == KEY_RIGHT_1)
		camera->angles.y -= RT_CAMERA_DIR_STEP;
	else if (key == KEY_DOWN_1)
		camera->angles.x += RT_CAMERA_DIR_STEP;
	else if (key == KEY_UP_1)
		camera->angles.x -= RT_CAMERA_DIR_STEP;
	else
		return (0);
	camera_recalculate(camera);
	return (1);
}

static int			rt_ctrl_light
	(t_rt *rt, t_camera *camera,t_light *light, int key)
{
	if (key == KEY_W)
		light_move(light, vector3_mul(&camera->axis_z, -RT_CAMERA_POS_STEP));
	else if (key == KEY_S)
		light_move(light, vector3_mul(&camera->axis_z, RT_CAMERA_POS_STEP));
	else if (key == KEY_A)
		light_move(light, vector3_mul(&camera->axis_x, -RT_CAMERA_POS_STEP));
	else if (key == KEY_D)
		light_move(light, vector3_mul(&camera->axis_x, RT_CAMERA_POS_STEP));
	else if (key == KEY_E)
		light_move(light, vector3_mul(&camera->axis_y, -RT_CAMERA_POS_STEP));
	else if (key == KEY_Q)
		light_move(light, vector3_mul(&camera->axis_y, RT_CAMERA_POS_STEP));
	else if (key == KEY_ENTER)
	{
		if (++rt->ctrl_light.index == (*rt->scenes.current)->lights_length)
			rt->ctrl_light.index = 0;
	}
	else
		return (0);
	return (1);
}

static int			rt_ctrl_shape
	(t_rt *rt, t_camera *camera,t_shape *shape, int key)
{
	if (key == KEY_W)
		shape_move(shape, vector3_mul(&camera->axis_z, -RT_CAMERA_POS_STEP));
	else if (key == KEY_S)
		shape_move(shape, vector3_mul(&camera->axis_z, RT_CAMERA_POS_STEP));
	else if (key == KEY_A)
		shape_move(shape, vector3_mul(&camera->axis_x, -RT_CAMERA_POS_STEP));
	else if (key == KEY_D)
		shape_move(shape, vector3_mul(&camera->axis_x, RT_CAMERA_POS_STEP));
	else if (key == KEY_E)
		shape_move(shape, vector3_mul(&camera->axis_y, -RT_CAMERA_POS_STEP));
	else if (key == KEY_Q)
		shape_move(shape, vector3_mul(&camera->axis_y, RT_CAMERA_POS_STEP));
	else if (key == KEY_ENTER)
	{
		shape->highlight = 0;
		if (++rt->ctrl_shape.index == (*rt->scenes.current)->shapes_length)
			rt->ctrl_shape.index = 0;
		(*rt->scenes.current)->shapes[rt->ctrl_shape.index].highlight = 1;
	}
	else
		return (0);
	return (1);
}

int 				rt_ctrl_scene(t_rt *rt, int key)
{
	t_camera		*camera;
	t_light			*light;
	t_shape			*shape;

	camera = &(*rt->scenes.current)->camera;
	light = &(*rt->scenes.current)->lights[rt->ctrl_light.index];
	shape = &(*rt->scenes.current)->shapes[rt->ctrl_shape.index];
	if (key == KEY_L)
		rt->ctrl_light.is_on = 1;
	else if (key == KEY_O)
	{
		(*rt->scenes.current)->shapes[rt->ctrl_shape.index].highlight = 1;
		rt->ctrl_shape.is_on = 1;
	}
	else if (rt->ctrl_light.is_on && rt_ctrl_light(rt, camera, light, key))
		;
	else if (rt->ctrl_shape.is_on && rt_ctrl_shape(rt, camera, shape, key))
		;
	else
		return (0);
	return (1);
}