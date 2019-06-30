#include "rt.h"



int					rt_key_press(int key, void *ptr)
{
	t_rt			**me;

	me = ptr;
	if (key == KEY_L)
		(*me)->ctrl_light.is_on = 1;
	else if (key == KEY_O)
	{
		scene_shape_at((*me)->scene, (*me)->ctrl_shape.index)->highlight = 1;
		(*me)->ctrl_shape.is_on = 1;
		rt_render((*me));
	}
	else if ((*me)->ctrl_light.is_on)
		rt_ctrl_light((*me), key);
	else if ((*me)->ctrl_shape.is_on)
		rt_ctrl_shape((*me), key);
	else if (key == KEY_W)
		vector3_s_sub_eq(&(*me)->camera->position, vector3_s_mul((*me)->camera->axis_z, RT_CAMERA_POS_STEP));
	else if (key == KEY_S)
		vector3_s_add_eq(&(*me)->camera->position, vector3_s_mul((*me)->camera->axis_z, RT_CAMERA_POS_STEP));
	else if (key == KEY_A)
		vector3_s_sub_eq(&(*me)->camera->position, vector3_s_mul((*me)->camera->axis_x, RT_CAMERA_POS_STEP));
	else if (key == KEY_D)
		vector3_s_add_eq(&(*me)->camera->position, vector3_s_mul((*me)->camera->axis_x, RT_CAMERA_POS_STEP));
	else if (key == KEY_E)
		(*me)->camera->position.y -= RT_CAMERA_POS_STEP;
	else if (key == KEY_Q)
		(*me)->camera->position.y += RT_CAMERA_POS_STEP;
	else if (key == KEY_LEFT_1)
		(*me)->camera->angles.y += RT_CAMERA_DIR_STEP;
	else if (key == KEY_RIGHT_1)
		(*me)->camera->angles.y -= RT_CAMERA_DIR_STEP;
	else if (key == KEY_DOWN_1)
		(*me)->camera->angles.x += RT_CAMERA_DIR_STEP;
	else if (key == KEY_UP_1)
		(*me)->camera->angles.x -= RT_CAMERA_DIR_STEP;
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
	rt_render((*me));
	return (0);
}

int					rt_key_release(int key, void *ptr)
{
	t_rt			*me;

	me = *(t_rt **)ptr;
	if (key == KEY_L)
		me->ctrl_light.is_on = 0;
	else if (key == KEY_O && me->ctrl_shape.is_on)
	{
		(*me->scenes.current)->shapes[me->ctrl_shape.index].highlight = 0;
		me->ctrl_shape.is_on = 0;
		rt_render(me);
	}
	return (0);
}

int					rt_exit(void *ptr)
{
	t_rt			**me;

	me = (t_rt **)ptr;
	rt_delete(&(*me)->clone);
	open_cl_delete(&(*me)->open_cl);
	rt_delete(me);
	exit(0);
}
