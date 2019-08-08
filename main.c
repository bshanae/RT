#include "gui.h"
#include "cl_renderer.h"

void				scene_test(t_scene *scene)
{
	object_build(
		(t_object *)scene_get_space(scene),
		object_sphere,
		(t_material){(RT_F4_API){1.}, (RT_F4_API){0.}},
		(RT_F4_API){-10., -10., -55.}, 2.);
	object_build(
		(t_object *)scene_get_space(scene),
		object_sphere,
		(t_material){(RT_F4_API){1.}, (RT_F4_API){0.}},
		(RT_F4_API){10., -10., -55.}, 2.);
	object_build(
		(t_object *)scene_get_space(scene),
		object_sphere,
		(t_material){(RT_F4_API){1.}, (RT_F4_API){0.}},
		(RT_F4_API){-10., 10., -55.}, 2.);
	object_build(
		(t_object *)scene_get_space(scene),
		object_sphere,
		(t_material){(RT_F4_API){1.}, (RT_F4_API){0.}},
		(RT_F4_API){10., 10., -55.}, 2.);
	object_build(
		(t_object *)scene_get_space(scene),
		object_sphere,
		(t_material){(RT_F4_API){1., 1., 1., 1.}, (RT_F4_API){10., 10., 10., 1.}},
		(RT_F4_API){0., 0., -50.}, 3.);
}

int					main(int argc, char **argv)
{
	t_gui			*gui;

	gui = gui_new(&argc, &argv);
	scene_test(gui->renderer->data_host.scene);
	gui_connect_renderer(gui);
	gui_loop(gui);
	gui_delete(&gui);
	return (0);
}