#include "renderer.h"
#include "shape_list.h"
#include "material_list.h"

int					main()
{
	t_renderer		*renderer;

	renderer = renderer_new();

#define CORNELL
#ifdef BAD_PLANE
	scene_add_shape(renderer->scene, shape_sphere((t_vector3){-0.1, .5, -5.}, .05, MATERIAL_LIGHT));
	scene_add_shape(renderer->scene, shape_sphere((t_vector3){0.1, .5, -5.}, .05, MATERIAL_LIGHT));

	scene_add_shape(renderer->scene, shape_sphere((t_vector3){0., 0., -6.}, .2, MATERIAL_RED));

	scene_add_shape(renderer->scene, shape_plane((t_vector3){0., -1., 0.}, (t_vector3){0., 1., 0.}, MATERIAL_WHITE)); // lower
	scene_add_shape(renderer->scene, shape_plane((t_vector3){0., 1.5, 0.}, (t_vector3){0., -1., 0.}, MATERIAL_WHITE)); // upper
	scene_add_shape(renderer->scene, shape_plane((t_vector3){-1.5, 0., 0.}, (t_vector3){1., 0., 0.}, MATERIAL_WHITE)); // left
	scene_add_shape(renderer->scene, shape_plane((t_vector3){1.5, 0., 0.}, (t_vector3){-1., 0., 0.}, MATERIAL_WHITE)); // right

	scene_add_shape(renderer->scene, shape_sphere((t_vector3){0., 0., -116.}, 100.2, MATERIAL_WHITE));
	//scene_add_shape(renderer->scene, shape_plane((t_vector3){0., 0., -12.}, (t_vector3){0., 0., 1.}, MATERIAL_GREY)); // back
//	scene_add_shape(renderer->scene, shape_plane((t_vector3){0., 0., 1.}, (t_vector3){0., 0., -1.}, MATERIAL_GREEN)); // front
#endif

#ifdef CORNELL
	renderer->camera->position = (t_vector3){0., 10., 180.};

	scene_add_shape(renderer->scene, shape_sphere((t_vector3){-10., 25., 25.}, 1.5, MATERIAL_LIGHT));
	scene_add_shape(renderer->scene, shape_sphere((t_vector3){10., 25., 25.}, 1.5, MATERIAL_LIGHT));

	scene_add_shape(renderer->scene, shape_sphere((t_vector3){15., 0., 50.}, 7., MATERIAL_WHITE));
	scene_add_shape(renderer->scene, shape_sphere((t_vector3){0., 0., 35.}, 7., MATERIAL_WHITE));
	scene_add_shape(renderer->scene, shape_sphere((t_vector3){-15., 0., 20.}, 7., MATERIAL_WHITE));

	scene_add_shape(renderer->scene, shape_plane((t_vector3){0., -15., 0.}, (t_vector3){0., 1., 0.}, MATERIAL_WHITE)); // lower
	scene_add_shape(renderer->scene, shape_plane((t_vector3){0., 35., 0.}, (t_vector3){0., -1., 0.}, MATERIAL_WHITE)); // upper
	scene_add_shape(renderer->scene, shape_plane((t_vector3){-30, 0., 0.}, (t_vector3){1., 0., 0.}, MATERIAL_GREEN)); // left
	scene_add_shape(renderer->scene, shape_plane((t_vector3){30., 0., 0.}, (t_vector3){-1., 0., 0.}, MATERIAL_RED)); // right

	scene_add_shape(renderer->scene, shape_plane((t_vector3){0., 0., -40.}, (t_vector3){0., 0., 1.}, MATERIAL_WHITE)); // back
#endif
	renderer_loop(&renderer);
	return (0);
}