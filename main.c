#include "gui.h"
#include "gui_signal_connect.h"
#include "cl_renderer.h"
#include "material_list.h"

void				scene_test(t_scene *scene)
{
	object_build(
		scene_get_space(scene), object_julia,
		MATERIAL_RED,
		50,
		(RT_F4_API){.1, .3, .5, .5});
//	object_build(
//		scene_get_space(scene), object_sphere,
//		MATERIAL_RED,
//		(RT_F4_API){-15., 0., 0.}, 7.);
//	object_build(
//		scene_get_space(scene), object_torus,
//		MATERIAL_WHITE,
//		(RT_F4_API){0., 10., 10.}, 20., 5.);
//	object_build(
//		scene_get_space(scene), object_sphere,
//		MATERIAL_GLASS,
//		(RT_F4_API){5., 0., 50.}, 7.);

	object_build(
		scene_get_space(scene), object_sphere,
		MATERIAL_LIGHT,
		(RT_F4_API){-10., 25., 45.}, 2.5);
	object_build(
		scene_get_space(scene), object_sphere,
		MATERIAL_LIGHT,
		(RT_F4_API){10., 25., 45.}, 2.5);

//	object_build( // front
//		scene_get_space(scene),
//		object_plane,
//		MATERIAL_WHITE,
//		(RT_F4_API){0., 0., -40.},
//		(RT_F4_API){0., 0., 1.});
//	object_build( // back
//		scene_get_space(scene),
//		object_plane,
//		MATERIAL_GREEN,
//		(RT_F4_API){0., 0., 120.},
//		(RT_F4_API){0., 0., -1.});
//	object_build( // left
//		scene_get_space(scene),
//		object_plane,
//		MATERIAL_GREEN,
//		(RT_F4_API){-30., 0., 0.},
//		(RT_F4_API){1., 0., 0.});
//	object_build( // right
//		scene_get_space(scene),
//		object_plane,
//		MATERIAL_RED,
//		(RT_F4_API){30., 0., 0.},
//		(RT_F4_API){-1., 0., 0.});
//	object_build( // upper
//		scene_get_space(scene),
//		object_plane,
//		MATERIAL_WHITE,
//		(RT_F4_API){0., 35., 0.},
//		(RT_F4_API){0., -1., 0.});
//	object_build( // lower
//		scene_get_space(scene),
//		object_plane,
//		MATERIAL_WHITE,
//		(RT_F4_API){0., -25., 0.},
//		(RT_F4_API){0., 1., 0.});
}

int					main(int argc, char **argv)
{
	t_gui			*gui;

	gui = gui_new(&argc, &argv);
	gui_signal_connect_all(gui);
	scene_test(gui->renderer->data.scene);
	gui->renderer->data.camera->position.z = 20.;
	gui_load(gui);
	gui_loop(gui);
	gui_delete(&gui);
	return (0);
}