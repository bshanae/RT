/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <ashari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 19:12:24 by ashari            #+#    #+#             */
/*   Updated: 2019/07/02 11:52:51 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static int			rt_choose_scene(t_rt *rt, int key)
{
	if (key == KEY_1)
		rt->scenes.current = &rt->scenes.data[0];
	else if (key == KEY_2)
		rt->scenes.current = &rt->scenes.data[1];
	else if (key == KEY_3)
		rt->scenes.current = &rt->scenes.data[2];
	else if (key == KEY_4)
		rt->scenes.current = &rt->scenes.data[3];
	else if (key == KEY_5)
		rt->scenes.current = &rt->scenes.data[4];
	else if (key == KEY_6)
		rt->scenes.current = &rt->scenes.data[5];
	else
		return (0);
	return (1);
}

int					rt_key_press(int key, void *ptr)
{
	t_rt			**rt;

	rt = ptr;
	if (key == KEY_ESC)
		rt_exit(rt);
	else if (key == KEY_R)
		rt_reset(rt);
	else if (rt_ctrl_scene(*rt, key))
		;
	else if (rt_ctrl_camera_move(*rt, key))
		;
	else if (rt_ctrl_camera_rotate(*rt, key))
		;
	else if (rt_choose_scene(*rt, key))
		;
	rt_render(*rt);
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
