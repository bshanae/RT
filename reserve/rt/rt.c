#include <camera.h>
#include "rt.h"

t_rt				*rt_new(void)
{
	t_rt			*rt;

	int				temp[3];
	if (!(rt = (t_rt *)malloc(sizeof(t_rt))))
		exit(21);
	rt->mlx_ptr = mlx_init();
	rt->win_ptr =
		mlx_new_window(rt->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "RT");
	rt->img_ptr =
		mlx_new_image(rt->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	temp[0] = 8 * 4;
	temp[1] = WINDOW_WIDTH * 4;
	temp[2] = 0;
	rt->img_data =
		(int *)mlx_get_data_addr(rt->img_ptr, temp, temp + 1, temp + 2);
	rt->scenes.length = 0;
	rt->scenes.index = 0;
	rt->scenes.current = &rt->scenes.data[0];
	rt->ctrl_light.is_on = 0;
	rt->ctrl_light.index = 0;
	rt->ctrl_shape.is_on = 0;
	rt->ctrl_shape.index = 0;
	rt_clone(rt);
	rt->open_cl = open_cl_new(rt->img_data);
	return (rt);
}

void				rt_delete(t_rt **me)
{
	int 			i;

	i = 0;
	while (i < (*me)->scenes.length)
		scene_delete(&(*me)->scenes.data[i++]);
	free(*me);
	*me = NULL;
}

void				rt_add_scene(t_rt *me, t_scene *scene)
{
	if (me->scenes.length < RT_SCENE_CAPACITY)
		me->scenes.data[me->scenes.length++] = scene;
}

void 				rt_render(t_rt *me)
{
	open_cl_run(me->open_cl, *me->scenes.current);
	mlx_put_image_to_window(me->mlx_ptr, me->win_ptr, me->img_ptr, 0, 0);
}