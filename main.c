#include "gui.h"
#include "gui_signal_connect.h"
#include "cl_renderer.h"
#include "material_list.h"

void				scene_fractals(t_scene *scene)
{
	object_build(
		scene_get_space(scene), object_julia,
		MATERIAL_RED,
		(RT_F4_API){0., 0., 10.},
		100,
		(RT_F4_API){.1, .3, .5, .5});
//
//	object_build(
//		scene_get_space(scene), object_mandelbulb,
//		MATERIAL_RED,
//		(RT_F4_API){0., 0., 0.},
//		50,	8.,	2.);
//	object_build(
//		scene_get_space(scene), object_tetrahedron,
//		MATERIAL_RED,
//		(RT_F4_API){0., 0., 0.},
//		100,	10.875);

	// LIGHT
	object_build(
		scene_get_space(scene), object_sphere,
		MATERIAL_LIGHT,
		(RT_F4_API){-5., 5., -15.}, 2.5);
	object_build(
		scene_get_space(scene), object_sphere,
		MATERIAL_LIGHT,
		(RT_F4_API){5., 5., 5.}, 2.5);
}

void				scene_room(t_scene *scene)
{
	object_build(
		scene_get_space(scene), object_sphere,
		MATERIAL_WHITE,
		(RT_F4_API){-10., -10., -10.}, 8.);

	object_build(
		scene_get_space(scene), object_sphere,
		MATERIAL_LIGHT,
		(RT_F4_API){10., 10., 10.}, 2.5);
	object_build(
		scene_get_space(scene), object_sphere,
		MATERIAL_LIGHT,
		(RT_F4_API){-10., 10., 10.}, 2.5);

	object_build( // front
		scene_get_space(scene),
		object_plane,
		MATERIAL_WHITE,
		(RT_F4_API){0., 0., -70.},
		(RT_F4_API){0., 0., 1.});
	object_build( // back
		scene_get_space(scene),
		object_plane,
		MATERIAL_WHITE,
		(RT_F4_API){0., 0., 140.},
		(RT_F4_API){0., 0., -1.});
	object_build( // left
		scene_get_space(scene),
		object_plane,
		MATERIAL_GREEN,
		(RT_F4_API){-30., 0., 0.},
		(RT_F4_API){1., 0., 0.});
	object_build( // right
		scene_get_space(scene),
		object_plane,
		MATERIAL_RED,
		(RT_F4_API){30., 0., 0.},
		(RT_F4_API){-1., 0., 0.});
	object_build( // upper
		scene_get_space(scene),
		object_plane,
		MATERIAL_WHITE,
		(RT_F4_API){0., 40., 0.},
		(RT_F4_API){0., -1., 0.});
	object_build( // lower
		scene_get_space(scene),
		object_plane,
		MATERIAL_WHITE,
		(RT_F4_API){0., -40., 0.},
		(RT_F4_API){0., 1., 0.});

}

int					main(int argc, char **argv)
{
	t_gui			*gui;

	gui = gui_new(&argc, &argv);
	gui_signal_connect_all(gui);
	//scene_fractals(gui->renderer->data.scene);
	scene_room(gui->renderer->data.scene);
	gui->renderer->data.camera->position.z = 120.;
	gui_load(gui);
	gui_loop(gui);
	gui_delete(&gui);
	return (0);
}