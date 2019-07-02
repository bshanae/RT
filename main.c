#include "rp.h"
#include "shape_list.h"
#include "material_list.h"

int 				main()
{
	t_rp			*rp;

	rp = rp_new();

	scene_add_light(rp->scene, (t_light){.5, (t_vector3){0., 0., 1.}});

	scene_add_shape(rp->scene, shape_sphere(
			(t_vector3){0., 0., -5.},
			.2,
			MATERIAL_RED));

	scene_add_shape(rp->scene, shape_plane(
			(t_vector3){0., -.25, 0.},
			(t_vector3){0., 1., 0.},
			MATERIAL_WHITE));

	scene_add_shape(rp->scene, shape_plane(
			(t_vector3){0., .3, 0.},
			(t_vector3){0., -1., 0.},
			MATERIAL_WHITE));

	scene_add_shape(rp->scene, shape_plane(
			(t_vector3){-.5, 0., 0.},
			(t_vector3){1., 0., 0.},
			MATERIAL_WHITE));

	scene_add_shape(rp->scene, shape_plane(
			(t_vector3){.5, 0., 0.},
			(t_vector3){-1., 0., 0.},
			MATERIAL_WHITE));

	rp_render(rp);

	mlx_hook(rp->win_ptr, 2, 1, rp_key_press, rp);
	mlx_hook(rp->win_ptr, 17u >> 1u, 1, rp_exit, rp);
	mlx_loop(rp->mlx_ptr);
}
