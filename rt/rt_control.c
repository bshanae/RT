/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_control.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <ashari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 19:12:14 by ashari            #+#    #+#             */
/*   Updated: 2019/06/30 19:12:15 by ashari           ###   ########.fr       */
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

void				rt_ctrl_light(t_rt *rt, int key)
{
	t_light			*light;

	light = &(*rt->scenes.current)->lights[rt->ctrl_light.index];
	if (key == KEY_W)
		light->vector.z -= RT_CAMERA_POS_STEP;
	else if (key == KEY_S)
		light->vector.z += RT_CAMERA_POS_STEP;
	else if (key == KEY_A)
		light->vector.x -= RT_CAMERA_POS_STEP;
	else if (key == KEY_D)
		light->vector.x += RT_CAMERA_POS_STEP;
	else if (key == KEY_E)
		light->vector.y -= RT_CAMERA_POS_STEP;
	else if (key == KEY_Q)
		light->vector.y += RT_CAMERA_POS_STEP;
	else if (key == KEY_ENTER)
	{
		if (++rt->ctrl_light.index == (*rt->scenes.current)->lights_length)
			rt->ctrl_light.index = 0;
	}
}

void				rt_ctrl_shape(t_rt *rt, int key)
{
	t_shape			*shape;
	t_camera		*camera;

	shape = &(*rt->scenes.current)->shapes[rt->ctrl_shape.index];
	camera = &(*rt->scenes.current)->camera;
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
}
