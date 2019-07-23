#include "mesh.h"
#include "mesh_parser.h"

static void				read_data(t_mesh_temp *temp, const char *file_name)
{
	int 				fd;
	char 				c;


	if ((fd = open(file_name, O_RDONLY)) == -1)
		exit(2);
	temp->file_length = 0;
	while (read(fd, &c, 1))
		temp->file_length++;
	temp->file_buffer = (char *)malloc(++temp->file_length);
	close(fd);
	fd = open(file_name,O_RDONLY);
	read(fd, temp->file_buffer, temp->file_length - 1);
	temp->file_buffer[temp->file_length - 1] = '\0';
}

static void				get_mesh(t_mesh *mesh, t_mesh_temp *temp, const t_material *material)
{
	int 				result;

	result = tinyobj_parse_obj(&temp->attributes,
								&temp->shapes, &temp->shapes_length,
								&temp->materials, &temp->materials_length,
								temp->file_buffer, temp->file_length,
								TINYOBJ_FLAG_TRIANGULATE);

	if (result != TINYOBJ_SUCCESS)
		exit(result);
	mesh->triangles = (t_triangle *)malloc(sizeof(t_triangle) * temp->attributes.num_faces);
	mesh->triangles_number = 0;
	mesh->material = *material;
	for (int face_i = 0; face_i < temp->attributes.num_faces; face_i += 3)
	{
		mesh->triangles[mesh->triangles_number++] = triangle_create
			(
				(t_vector3 *)(temp->attributes.vertices) + temp->attributes.faces[face_i + 0].v_idx,
				(t_vector3 *)(temp->attributes.vertices) + temp->attributes.faces[face_i + 1].v_idx,
				(t_vector3 *)(temp->attributes.vertices) + temp->attributes.faces[face_i + 2].v_idx,
				temp->attributes.num_normals ?
					(t_vector3 *)(temp->attributes.normals) + temp->attributes.faces[face_i + 0].vn_idx :
					NULL
			);
	}
}

static void				clean_temp(t_mesh_temp *temp)
{
	free(temp->file_buffer);
	tinyobj_attrib_free(&temp->attributes);
	tinyobj_shapes_free(temp->shapes, temp->shapes_length);
	tinyobj_materials_free(temp->materials, temp->materials_length);
}

t_mesh					*mesh_new(const char *file_name, t_material material)
{
	t_mesh				*new;
	t_mesh_temp			temp;

	new = (t_mesh *)malloc(sizeof(t_mesh));
	read_data(&temp, file_name);
	get_mesh(new, &temp, &material);
	clean_temp(&temp);
	return (new);
}