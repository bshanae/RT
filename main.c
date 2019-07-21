#include "renderer.h"
#include "shape_list.h"
#include "material_list.h"

#include "objpar.h"
#include "open_file.h"

void 				test()
{
	char 			*file_name;
	size_t 			file_size;
	void 			*buffer[2];
	objpar_data_t	data;
	objpar_mesh_t	mesh;

	file_name = "../obj_tests/cube.obj";
	buffer[0] = open_file(file_name, &file_size);
	buffer[1] = malloc(objpar_get_size(buffer[0], file_size));
	objpar((const char *)buffer[0], file_size, buffer[1], &data);
	free(buffer[0]);

	printf("Geometry Vertices Count: %u\n", data.position_count);
	printf("Vertex Normals Count: %u\n", data.normal_count);
	printf("Texture Vertices Count: %u\n", data.texcoord_count);
	printf("Face Count: %u\n\n", data.face_count);

	printf("Geometry Vertices:\n");
	for (int index = 0; index < data.position_count * data.position_width; index += data.position_width)
	{
		unsigned int j;
		putc('\t', stdout);
		for (j = 0; j < data.position_width; ++j)
		{
			float v = data.p_positions[index + j];
			printf("%f\t", v);
		}
		putc('\n', stdout);
	}

	printf("\nVertex Normals:\n");
	for (int index = 0; index < data.normal_count * data.normal_width; index += data.normal_width)
	{
		unsigned int j;
		putc('\t', stdout);
		for (j = 0; j < data.normal_width; ++j)
		{
			float v = data.p_normals[index + j];
			printf("%f\t", v);
		}
		putc('\n', stdout);
	}

	printf("\nTexture Vertices:\n");
	for (int index = 0; index < data.texcoord_count * data.texcoord_width; index += data.texcoord_width)
	{
		unsigned int j;
		putc('\t', stdout);
		for (j = 0; j < data.texcoord_width; ++j)
		{
			float v = data.p_texcoords[index + j];
			printf("%f\t", v);
		}
		putc('\n', stdout);
	}

	printf("\nFaces:\n");
	for (int index = 0; index < data.face_count * data.face_width * 3; index += data.face_width * 3)
	{
		unsigned int j;
		putc('\t', stdout);
		for (j = 0; j < data.face_width * 3; j += 3)
		{
			unsigned int v = data.p_faces[index + j + OBJPAR_V_IDX];
			unsigned int vn = data.p_faces[index + j + OBJPAR_VN_IDX];
			unsigned int vt = data.p_faces[index + j + OBJPAR_VT_IDX];

			printf("%u/%u/%u\t", v, vt, vn);
		}
		putc('\n', stdout);

	}
	exit(0);
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