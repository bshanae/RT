#include <camera.h>
#include "rt.h"

t_rt				*rt_new()
{
	t_rt			*rt;

	int				temp[3];
	if (!(rt = (t_rt *)malloc(sizeof(t_rt))))
		exit(21);
	rt->mlx_ptr = mlx_init();
	rt->win_ptr = mlx_new_window(rt->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "RT");
	rt->img_ptr = mlx_new_image(rt->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	temp[0] = 8 * 4;
	temp[1] = WIN_WIDTH * 4;
	temp[2] = 0;
	rt->img_data = (int *)mlx_get_data_addr(rt->img_ptr, temp, temp + 1, temp + 2);
	rt->camera = camera_new(WIN_WIDTH / (tan((M_PI / 3.) / 2.)));
	rt->scene = scene_new(DEF_BACKGROUND);
	rt->light_ctrl.is_on = 0;
	rt->light_ctrl.index = 0;
	rt->object_ctrl.is_on = 0;
	rt->object_ctrl.index = 0;
	rt->clone = NULL;
	rt->console = console_new(rt->mlx_ptr,rt->win_ptr, rt->img_ptr,rt->img_data, WIN_WIDTH, WIN_HEIGHT);
	rt->settings.parallel = 1;
	rt->settings.reflection_depth = REFLECTION_DEPTH;
	rt->settings.refraction_depth = REFRACTION_DEPTH;
	rt->settings.diffuse_light = &rt->scene->settings.diffuse_light;
	rt->settings.specular_light = &rt->scene->settings.specular_light;
	rt->settings.shadows = &rt->scene->settings.shadows;
	rt->settings.tshadows = &rt->scene->settings.tshadows;
	rt->open_cl = open_cl_new(rt->img_data, WIN_WIDTH, WIN_HEIGHT);
	return (rt);
}

void				rt_delete(t_rt **me)
{
	camera_delete(&(*me)->camera);
	scene_delete(&(*me)->scene);
	console_delete(&(*me)->console);
	free((*me)->console);
	free(*me);
	*me = NULL;
}

void 				rt_reset(t_rt **me)
{
	t_rt			*old;

	old = *me;
	*me = (*me)->clone;
	(*me)->open_cl = old->open_cl;
	(*me)->clone = NULL;
	rt_delete(&old);
	rt_clone(*me);
}

void 				rt_clone(t_rt *me)
{
	u_long			i;
	t_shape			*shape[2];
	t_light			*light[2];

	if (!(me->clone = (t_rt *)malloc(sizeof(t_rt))))
		exit(21);
	me->clone->mlx_ptr = me->mlx_ptr;
	me->clone->win_ptr = me->win_ptr;
	me->clone->img_ptr = me->img_ptr;
	me->clone->img_data = me->img_data;
	me->clone->camera = camera_new(WIN_WIDTH / (tan((M_PI / 3.) / 2.)));
	me->clone->camera->position = me->camera->position;
	me->clone->scene = scene_new(DEF_BACKGROUND);
	me->clone->scene->background = me->scene->background;
	i = 0;
	while (i < me->scene->shapes.length)
	{
		shape[0] = scene_shape_at(me->scene, i++);
		shape[1] = (t_shape *)malloc(sizeof(t_shape));
		ft_memcpy(shape[1], shape[0], sizeof(t_shape));
		shape[1]->data = malloc(shape[1]->data_size);
		ft_memcpy(shape[1]->data, shape[0]->data, shape[1]->data_size);
		scene_shape_push(me->clone->scene, shape[1]);
	}
	i = 0;
	while (i < me->scene->lights.length)
	{
		light[0] = scene_light_at(me->scene, i++);
		light[1] = (t_light *)malloc(sizeof(t_light));
		ft_memcpy(light[1], light[0], sizeof(t_light));
		scene_light_push(me->clone->scene, light[1]);
	}
	me->clone->light_ctrl.is_on = 0;
	me->clone->light_ctrl.index = 0;
	me->clone->object_ctrl.is_on = 0;
	me->clone->object_ctrl.index = 0;
	me->clone->console = console_new(me->mlx_ptr,me->win_ptr, me->img_ptr,me->img_data, WIN_WIDTH, WIN_HEIGHT);
	me->clone->settings.parallel = 0;
	me->clone->settings.reflection_depth = 5;
	me->clone->settings.refraction_depth = 5;
	me->clone->settings.diffuse_light = &me->clone->scene->settings.diffuse_light;
	me->clone->settings.specular_light = &me->clone->scene->settings.specular_light;
	me->clone->settings.shadows = &me->clone->scene->settings.shadows;
	me->clone->settings.tshadows = &me->clone->scene->settings.tshadows;
	me->clone->open_cl = NULL;
}

void				rt_set_camera(t_rt *me, t_vector3 position)
{
	me->camera->position = position;
}

void				rt_set_background(t_rt *me, t_vector3 color)
{
	me->scene->background = color;
}

void				rt_perform(t_rt **me)
{
	if ((*me)->console->code == reflect_on)
			(*me)->settings.reflection_depth = 1;
	else if ((*me)->console->code == reflect_off)
			(*me)->settings.reflection_depth = 0;
	else if ((*me)->console->code == reflect_value)
			(*me)->settings.reflection_depth = (*me)->console->value;
	else if ((*me)->console->code == refract_on)
			(*me)->settings.refraction_depth = 1;
	else if ((*me)->console->code == refract_off)
			(*me)->settings.refraction_depth = 0;
	else if ((*me)->console->code == refract_value)
			(*me)->settings.refraction_depth = (*me)->console->value;
	else if ((*me)->console->code == diffuse_on)
		*(*me)->settings.diffuse_light = 1;
	else if ((*me)->console->code == diffuse_off)
		*(*me)->settings.diffuse_light = 0;
	else if ((*me)->console->code == specular_on)
		*(*me)->settings.specular_light = 1;
	else if ((*me)->console->code == specular_off)
		*(*me)->settings.specular_light = 0;
	else if ((*me)->console->code == shadows_on)
		*(*me)->settings.shadows = 1;
	else if ((*me)->console->code == shadows_off)
		*(*me)->settings.shadows = 0;
	else if ((*me)->console->code == tshadows_on)
		*(*me)->settings.tshadows = 1;
	else if ((*me)->console->code == tshadows_off)
		*(*me)->settings.tshadows = 0;
	else if ((*me)->console->code == reset)
		rt_reset(me);
	else if ((*me)->console->code == parallel_on)
		(*me)->settings.parallel = 1;
	else if ((*me)->console->code == parallel_off)
		(*me)->settings.parallel = 0;
	rt_render(*me);
}

void 				rt_render(t_rt *me)
{
	if (me->settings.parallel)
		rt_parallel(me);
	else
		rt_consistent(me);
}

void				rt_build_open_cl(t_rt *me)
{
	open_cl_alloc_device(me->open_cl, me->scene);
	open_cl_set_args(me->open_cl);
}