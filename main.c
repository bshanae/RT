#include "rt.h"
#include "shape_list.h"

#include "test.c"

typedef struct 		s_vector2f
{
	float 			x;
	float 			y;
}					t_vector2f;

int 				main()
{
	t_rt			*rt;

	t_vector3		*back;
	t_vector3		*red;
	t_vector3		*white;
	t_vector3		*blue;

	t_material		*white_material;
	t_material		*red_material;
	t_material		*blue_material;
	t_material		*mirror;
	t_material		*glass;

	back = vector3_new(1, .7);

	red = vector3_new(3, .9, .1, .1);
	white = vector3_new(1, .9);
	blue = vector3_new(3, .1, .1, .9);

	white_material = material_new(*white, 1., .0, .0, .0);
	red_material = material_new(*red, 1., .3, .0, .0);
	blue_material = material_new(*blue, 1., 1.1, 0.5, 0.1);
	mirror = material_new(*blue, .1, 4.1, .8, 0.);
	glass = material_new(*white, .1, .9, 0., 0.9);

	rt = rt_new();

//	rt_set_camera(rt, (t_vector3) {0., .5, 8.});
//	//rt_set_camera(rt, (t_vector3) {0., .5, 0.},  (t_vector3) {0., -1., 0.});
//
//	rt_set_background(rt, *back);
//
//	scene_shape_push(rt->scene, shape_sphere((t_vector3) {-1.3, .7, -15.}, .7, red_material));
//	scene_shape_push(rt->scene, shape_sphere((t_vector3) {-2., .9, -10.}, .3, glass));
//	//scene_shape_push(rt->scene, shape_sphere((t_vector3) {0., 0., 0.}, .03, blue_material));
//	//scene_shape_push(rt->scene, shape_sphere((t_vector3) {0.1, 0., 0.}, .03, blue_material));
//	//scene_shape_push(rt->scene, shape_sphere((t_vector3) {0.2, 0., 0.}, .03, blue_material));
//
//	for (int i = 0; i < 2; i++)
//	{
//		float p = (float)i;
//		scene_shape_push(rt->scene, shape_sphere((t_vector3) {p, 0., 3.}, .3, glass));
//	}
//
//	for (int i = 0; i < 2; i++)
//	{
//		float p = (float)i;
//		scene_shape_push(rt->scene, shape_sphere((t_vector3) {p, 0., 4.}, .1, red_material));
//	}
//
//	//scene_shape_push(rt->scene, shape_cylinder((t_vector3) {0., 1., -1.}, (t_vector3) {0., 0., -1.}, .5, red_material));
//
//	//scene_shape_push(rt->scene, shape_plane((t_vector3) {0., -0.5, 0.}, (t_vector3) {0., 1., 0.}, mirror));
//
//	//scene_shape_push(rt->scene, shape_aabb((t_vector3){0., 0., 0.}, (t_vector3){1., 1., 1.}, mirror));
//
//	//scene_shape_push(rt->scene, shape_cone((t_vector3){0., 1., 0.}, (t_vector3){0., 0., 0.}, 20., red_material));
//
//	scene_shape_push(rt->scene, shape_disk((t_vector3) {0., 0., 0.}, (t_vector3) {0., 1., 1.}, .2, red_material));
//
//	//scene_light_push(rt->scene, light_new(light_ambient, 0.1));
//	//scene_light_push(rt->scene, light_new(light_point, .9, (t_vector3){2., 0., -15.}));
//	scene_light_push(rt->scene, light_new(light_point, .9, (t_vector3){0., 5., 5.}));
//	//scene_light_push(rt->scene, light_new(light_point, .9, (t_vector3){0., 5., 30.}));
//
//	rt_clone(rt);
//	rt_build_open_cl(rt);
//
//	rt_render(rt);

//	mlx_hook(rt->win_ptr, 2, 1, rt_key_press, &rt);
//	mlx_hook(rt->win_ptr, 3, 1, rt_key_release, &rt);
//	mlx_hook(rt->win_ptr, 17u >> 1u, 1, rt_exit, &rt);
	mlx_loop(rt->mlx_ptr);
}
