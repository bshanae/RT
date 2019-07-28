#include "rt.h"
#include "shape_list.h"

int 				main()
{
	t_rt			*rt;

	t_vector3		*back;
	t_vector3		*red;
	t_material		*red_material;

	back = vector3_new(1, .7);

	red = vector3_new(3, .9, .1, .1);
	red_material = material_new(*red, 1., .3, .0, .0);

	rt = rt_new();

	rt_set_camera(rt, (t_vector3) {0., 1.5, 40.});
	rt_set_background(rt, *back);

//	scene_shape_push(rt->scene, shape_moebius(1, 0.5, (t_vector3){0., 0., 0.}, red_material));
	scene_shape_push(rt->scene, shape_paraboloid((t_vector3){0., 0., 0.}, (t_vector3){0., 1., 0.}, .5, red_material));

	scene_light_push(rt->scene, light_new(light_point, .9, (t_vector3){0., 5., 5.}));

	rt_render(rt);

	mlx_hook(rt->win_ptr, 2, 1, rt_key_press, &rt);
	mlx_hook(rt->win_ptr, 3, 1, rt_key_release, &rt);
	mlx_hook(rt->win_ptr, 17u >> 1u, 1, rt_exit, &rt);
	mlx_loop(rt->mlx_ptr);
}
