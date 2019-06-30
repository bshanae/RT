#include "rt.h"

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

	shape = &(*rt->scenes.current)->shapes[rt->ctrl_shape.index];
	if (key == KEY_W)
		shape->move(shape, vector3_mul(&rt->camera->axis_z, -RT_CAMERA_POS_STEP));
	else if (key == KEY_S)
		shape->move(shape, vector3_mul(&rt->camera->axis_z, RT_CAMERA_POS_STEP));
	else if (key == KEY_A)
		shape->move(shape, vector3_mul(&rt->camera->axis_x, -RT_CAMERA_POS_STEP));
	else if (key == KEY_D)
		shape->move(shape, vector3_mul(&rt->camera->axis_x, RT_CAMERA_POS_STEP));
	else if (key == KEY_E)
		shape->move(shape, vector3_mul(&rt->camera->axis_y, -RT_CAMERA_POS_STEP));
	else if (key == KEY_Q)
		shape->move(shape, vector3_mul(&rt->camera->axis_y, RT_CAMERA_POS_STEP));
	else if (key == KEY_ENTER)
	{
		shape->highlight = 0;
		if (++rt->ctrl_shape.index == rt->scene->shapes.length)
			rt->ctrl_shape.index = 0;
		scene_shape_at(rt->scene, rt->ctrl_shape.index)->highlight = 1;
	}
}