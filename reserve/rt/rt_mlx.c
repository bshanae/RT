#include "rt.h"



int					rt_key_press(int key, void *ptr)
{
	t_rt			**rt;

	rt = ptr;
	if (key == KEY_ESC)
		rt_exit(rt);
	else if (key == KEY_R)
		rt_reset(rt);
	else if (rt_ctrl_camera_move(*rt, key))
		;
	else if (rt_ctrl_camera_rotate(*rt, key))
		;
	else if (key == KEY_L)
		(*rt)->ctrl_light.is_on = 1;
	else if (key == KEY_O)
	{
		(*(*rt)->scenes.current)->shapes[(*rt)->ctrl_shape.index].highlight = 1;
		(*rt)->ctrl_shape.is_on = 1;
//		rt_render((*rt));
	}
	else if ((*rt)->ctrl_light.is_on)
		rt_ctrl_light((*rt), key);
	else if ((*rt)->ctrl_shape.is_on)
		rt_ctrl_shape((*rt), key);
	else
		return (0);
	rt_render((*rt));
	return (0);
}

int					rt_key_release(int key, void *ptr)
{
	t_rt			*rt;

	rt = *(t_rt **)ptr;
	if (key == KEY_L)
		rt->ctrl_light.is_on = 0;
	else if (key == KEY_O && rt->ctrl_shape.is_on)
	{
		(*rt->scenes.current)->shapes[rt->ctrl_shape.index].highlight = 0;
		rt->ctrl_shape.is_on = 0;
		rt_render(rt);
	}
	return (0);
}

int					rt_exit(void *ptr)
{
	t_rt			**rt;

	rt = (t_rt **)ptr;
	rt_delete(&(*rt)->clone);
	open_cl_delete(&(*rt)->open_cl);
	rt_delete(rt);
	exit(0);
}
