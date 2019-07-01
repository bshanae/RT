#include "scene_list.h"

t_scene				*scene_a(void)
{
	t_scene			*scene;

	scene = scene_new();

	scene->camera.position = (t_vector3) {0., .5, 8.};

	//scene_add_light(scene, light_create(light_ambient, 0.1));
	//scene_add_light(scene, light_create(light_point, .9, (t_vector3){2., 0., 10.}));
	scene_add_light(scene, light_create(light_point, .7, (t_vector3) {0., 5., 5.}));

	scene_add_shape(scene, shape_aabb((t_vector3){0., 0., 0.}, (t_vector3){1., 1., 1.}, MATERIAL_MIRROR));

	scene_add_shape(scene, shape_sphere((t_vector3) {-.7, -.5, 1.}, .3, MATERIAL_RED));
	scene_add_shape(scene, shape_sphere((t_vector3) {0., -.5, 1.}, .3, MATERIAL_RED));
	scene_add_shape(scene, shape_sphere((t_vector3) {.7, -.5, 1.}, .3, MATERIAL_RED));

	scene_add_shape(scene, shape_sphere((t_vector3) {0., 0., 0.}, .5, MATERIAL_MIRROR));

	return (scene);
}