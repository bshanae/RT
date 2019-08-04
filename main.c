#include "gui.h"
#include "renderer.h"
#include "object_build.h"

void				scene_test(t_scene *scene)
{
	object_build(
			(t_object *)scene_get_space(scene, SCENE_SPACE_OBJECT),
			object_sphere,
			(t_vector3){0.1, 0., 0.}, 1.);
	object_build(
			(t_object *)scene_get_space(scene, SCENE_SPACE_OBJECT),
			object_plane,
			(t_vector3){0., -1., 0.},
			(t_vector3){0., 1., 0.});
}

int					main(int argc, char **argv)
{
	t_gui			*gui;
	t_renderer		*renderer;

	gui = gui_new();
	gui_init(gui, &argc, &argv);

	renderer = renderer_new();
	scene_test(renderer->scene);

	gui_connect_renderer(gui, renderer);

	gui_start(gui);

	printf("object0 = %f\n",
		   *(double *)renderer->scene->objects->data);

	return (0);
}