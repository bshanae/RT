#include "gui.h"
#include "cl_renderer.h"

void				scene_test(t_scene *scene)
{
	object_build(
		(t_object *)scene_get_space(scene, SCENE_SPACE_OBJECT),
		object_sphere,
		(t_vector3){0., 0., -5.}, .1);
	object_build(
		(t_object *)scene_get_space(scene, SCENE_SPACE_OBJECT),
		object_plane,
		(t_vector3){0., -1., 0.},
		(t_vector3){0., 1., 0.});
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