#include "rt.h"

void				rt_light_ctrl(t_rt *me, int key)
{
	t_light			*light;

	light = scene_light_at(me->scene, me->light_ctrl.index);
	if (key == KEY_W)
		light->vector.z -= CAMERA_POS_STEP;
	else if (key == KEY_S)
		light->vector.z += CAMERA_POS_STEP;
	else if (key == KEY_A)
		light->vector.x -= CAMERA_POS_STEP;
	else if (key == KEY_D)
		light->vector.x += CAMERA_POS_STEP;
	else if (key == KEY_E)
		light->vector.y -= CAMERA_POS_STEP;
	else if (key == KEY_Q)
		light->vector.y += CAMERA_POS_STEP;
	else if (key == KEY_ENTER)
	{
		if (++me->light_ctrl.index == me->scene->lights.length)
			me->light_ctrl.index = 0;
	}
}

void				rt_object_ctrl(t_rt *me, int key)
{
	t_shape			*shape;

	shape = scene_shape_at(me->scene, me->object_ctrl.index);
	if (key == KEY_W)
		shape->move(shape, vector3_mul(&me->camera->axis_z, -CAMERA_POS_STEP));
	else if (key == KEY_S)
		shape->move(shape, vector3_mul(&me->camera->axis_z, CAMERA_POS_STEP));
	else if (key == KEY_A)
		shape->move(shape, vector3_mul(&me->camera->axis_x, -CAMERA_POS_STEP));
	else if (key == KEY_D)
		shape->move(shape, vector3_mul(&me->camera->axis_x, CAMERA_POS_STEP));
	else if (key == KEY_E)
		shape->move(shape, vector3_mul(&me->camera->axis_y, -CAMERA_POS_STEP));
	else if (key == KEY_Q)
		shape->move(shape, vector3_mul(&me->camera->axis_y, CAMERA_POS_STEP));
	else if (key == KEY_ENTER)
	{
		shape->highlight = 0;
		if (++me->object_ctrl.index == me->scene->shapes.length)
			me->object_ctrl.index = 0;
		scene_shape_at(me->scene, me->object_ctrl.index)->highlight = 1;
	}
}

int					rt_key_press(int key, void *ptr)
{
	t_rt			**me;

	me = ptr;
	if (key == KEY_COLON && (*me)->console->shift)
		console_launch((*me)->console);
	else if (key == KEY_SHIFT)
		(*me)->console->shift = 1;
	else if ((*me)->console->is_on)
	{
		if (console_get((*me)->console, key))
			rt_perform(me);
	}
	else if (key == KEY_L)
		(*me)->light_ctrl.is_on = 1;
	else if (key == KEY_O)
	{
		scene_shape_at((*me)->scene, (*me)->object_ctrl.index)->highlight = 1;
		(*me)->object_ctrl.is_on = 1;
		rt_render((*me));
	}
	else if ((*me)->light_ctrl.is_on)
		rt_light_ctrl((*me), key);
	else if ((*me)->object_ctrl.is_on)
		rt_object_ctrl((*me), key);
	else if (key == KEY_W)
		vector3_s_sub_eq(&(*me)->camera->position, vector3_s_mul((*me)->camera->axis_z, CAMERA_POS_STEP));
	else if (key == KEY_S)
		vector3_s_add_eq(&(*me)->camera->position, vector3_s_mul((*me)->camera->axis_z, CAMERA_POS_STEP));
	else if (key == KEY_A)
		vector3_s_sub_eq(&(*me)->camera->position, vector3_s_mul((*me)->camera->axis_x, CAMERA_POS_STEP));
	else if (key == KEY_D)
		vector3_s_add_eq(&(*me)->camera->position, vector3_s_mul((*me)->camera->axis_x, CAMERA_POS_STEP));
	else if (key == KEY_E)
		(*me)->camera->position.y -= CAMERA_POS_STEP;
	else if (key == KEY_Q)
		(*me)->camera->position.y += CAMERA_POS_STEP;
	else if (key == KEY_LEFT_1)
		(*me)->camera->angles.y += CAMERA_DIR_STEP;
	else if (key == KEY_RIGHT_1)
		(*me)->camera->angles.y -= CAMERA_DIR_STEP;
	else if (key == KEY_DOWN_1)
		(*me)->camera->angles.x += CAMERA_DIR_STEP;
	else if (key == KEY_UP_1)
		(*me)->camera->angles.x -= CAMERA_DIR_STEP;
	else if (key == KEY_R)
		rt_reset(me);
	else if (key == KEY_P)
		(*me)->settings.parallel = !(*me)->settings.parallel;
	else if (key == KEY_ESC)
		exit(1);
	else
		return (0);
	if (key == KEY_LEFT_1 || key == KEY_RIGHT_1 || key == KEY_DOWN_1 || key == KEY_UP_1)
		camera_recalculate((*me)->camera);
	if (!(*me)->console->is_on)
		rt_render((*me));
	return (0);
}

int					rt_key_release(int key, void *ptr)
{
	t_rt			*me;

	me = *(t_rt **)ptr;
	if (key == KEY_L)
		me->light_ctrl.is_on = 0;
	else if (key == KEY_O && me->object_ctrl.is_on)
	{
		scene_shape_at(me->scene, me->object_ctrl.index)->highlight = 0;
		me->object_ctrl.is_on = 0;
		rt_render(me);
	}
	else if (key == KEY_SHIFT)
		me->console->shift = 0;
	return (0);
}

int					rt_exit(void *ptr)
{
	t_rt			**me;

	me = (t_rt **)ptr;
	rt_delete(&(*me)->clone);
	rt_delete(me);
//	open_cl_delete(&(*me)->open_cl);
	exit(0);
}
