#include "gui.h"
#include "cl_renderer.h"

void				scene_test(t_scene *scene)
{
	for (int i = -5; i < 5; i++)
		object_build(
			(t_object *)scene_get_space(scene, SCENE_SPACE_OBJECT),
			object_sphere,
			(t_material){(API_FLOAT4){1.}, (API_FLOAT4){0.}},
			(API_FLOAT4){0., (FLOAT)i / 3., -5.}, .1);
	object_build(
		(t_object *)scene_get_space(scene, SCENE_SPACE_OBJECT),
		object_sphere,
		(t_material){(API_FLOAT4){1., 1., 1., 1.}, (API_FLOAT4){1., 1., 1., 1.}},
		(API_FLOAT4){-3., 0., -5.}, .1);
//	object_build(
//		(t_object *)scene_get_space(scene, SCENE_SPACE_OBJECT),
//		object_plane,
//		(API_FLOAT4){0., 0., 0.},
//		(API_FLOAT4){0., 1., 0.});
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