#include "renderer.h"
#include "shape_list.h"
#include "material_list.h"

int					main()
{
	t_renderer		*renderer;

	renderer = renderer_new();

	scene_add_shape(renderer->scene, shape_sphere((t_vector3){0., 1., -14.}, .2, MATERIAL_LIGHT));

	scene_add_shape(renderer->scene, shape_sphere((t_vector3){0., 0., -15.}, .5, MATERIAL_RED));

	scene_add_shape(renderer->scene, shape_plane((t_vector3){0., -1., 0.}, (t_vector3){0., 1., 0.}, MATERIAL_WHITE)); // lower
//	scene_add_shape(renderer->scene, shape_plane((t_vector3){0., 2., 0.}, (t_vector3){0., -1., 0.}, MATERIAL_WHITE)); // upper
//	scene_add_shape(renderer->scene, shape_plane((t_vector3){-2., 0., 0.}, (t_vector3){1., 0., 0.}, MATERIAL_WHITE)); // left
//	scene_add_shape(renderer->scene, shape_plane((t_vector3){2., 0., 0.}, (t_vector3){-1., 0., 0.}, MATERIAL_WHITE)); // right

	renderer_loop(&renderer);
	return (0);
}