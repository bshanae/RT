#include "renderer.h"
#include "shape_list.h"
#include "material_list.h"

#include "objpar.h"
#include "open_file.h"

void 				test()
{
	char 			*file_name;
	size_t 			file_size;
	void 			*buffer;
	objpar_data_t	data;

	file_name = NULL;
	file_name = open_file(file_name, &file_size);
	buffer = malloc(objpar_get_size(file_name, file_size));
	objpar(file_name, file_size, buffer, &data);
	free(buffer);

	printf("Geometry Vertices Count: %u\n", data.position_count);
	printf("Vertex Normals Count: %u\n", data.normal_count);
	printf("Texture Vertices Count: %u\n", data.texcoord_count);
	printf("Face Count: %u\n\n", data.face_count);
}

int					main()
{
	t_renderer		*renderer;

	test();

	renderer = renderer_new();

	renderer->camera->position = (t_vector3){0., 10., 180.};

	scene_add_shape(renderer->scene, shape_triangle((t_vector3) {-10., -5., 0.},
													(t_vector3) {10., -5., 0.},
													(t_vector3) {0., 5., 0.},
								  					MATERIAL_LIGHT));

//	scene_add_shape(renderer->scene, shape_sphere((t_vector3){-10., 25., 45.}, 2.5, MATERIAL_LIGHT));
//	scene_add_shape(renderer->scene, shape_sphere((t_vector3){10., 25., 25.}, 2.5, MATERIAL_LIGHT));
//
//	scene_add_shape(renderer->scene, shape_sphere((t_vector3){-15., 0., 0.}, 7., MATERIAL_MIRROR));
//	scene_add_shape(renderer->scene, shape_sphere((t_vector3){0., 0., 20.}, 7., MATERIAL_WHITE));
//	scene_add_shape(renderer->scene, shape_sphere((t_vector3){5., 0., 50.}, 7., MATERIAL_GLASS));
//
//	scene_add_shape(renderer->scene, shape_plane((t_vector3){0., -15., 0.}, (t_vector3){0., 1., 0.}, MATERIAL_WHITE)); // lower
//	scene_add_shape(renderer->scene, shape_plane((t_vector3){0., 35., 0.}, (t_vector3){0., -1., 0.}, MATERIAL_WHITE)); // upper
//	scene_add_shape(renderer->scene, shape_plane((t_vector3){-30, 0., 0.}, (t_vector3){1., 0., 0.}, MATERIAL_GREEN)); // left
//	scene_add_shape(renderer->scene, shape_plane((t_vector3){30., 0., 0.}, (t_vector3){-1., 0., 0.}, MATERIAL_RED)); // right
//
//	scene_add_shape(renderer->scene, shape_plane((t_vector3){0., 0., -40.}, (t_vector3){0., 0., 1.}, MATERIAL_WHITE)); // back
//	scene_add_shape(renderer->scene, shape_plane((t_vector3){0., 0., 190.}, (t_vector3){0., 0., 1.}, MATERIAL_WHITE)); // front

	renderer_loop(&renderer);
	return (0);
}