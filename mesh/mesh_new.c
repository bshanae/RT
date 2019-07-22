#include "mesh.h"

static void				read_data(t_mesh_temp *temp, const char *file_name)
{
	u_long 				file_size;

	temp->buffer[0] = open_file(file_name, &file_size);
	temp->buffer[1] = malloc(objpar_get_size(temp->buffer[0], file_size));
	objpar((const char *)temp->buffer[0], file_size, temp->buffer[1], &temp->obj);
	temp->buffer[2] = malloc(objpar_get_mesh_size(&temp->obj));
	assert(objpar_build_mesh(&temp->obj, temp->buffer[2], &temp->mesh));
	temp->vertices = (float *)temp->mesh.p_vertices;
}

static void				get_mesh(t_mesh *mesh, t_mesh_temp *temp, const t_material *material)
{
	float 				*ptr[3];

	if (temp->mesh.texcoord_offset != -1 || temp->mesh.normal_offset == -1)
		exit(21);
	mesh->triangles = (t_triangle *)malloc(sizeof(t_triangle) * temp->obj.face_count);
	mesh->triangles_number = 0;
	mesh->material = *material;
	for (int i = 0; i < temp->mesh.vertex_count; i += 3)
	{
		ptr[0] = &temp->vertices[i * 6];
		ptr[1] = &temp->vertices[(i + 1) * 6];
		ptr[2] = &temp->vertices[(i + 2) * 6];
		mesh->triangles[mesh->triangles_number++] = triangle_create
			(
				(t_vector3 *)(ptr[0]),
				(t_vector3 *)(ptr[1]),
				(t_vector3 *)(ptr[2]),
				(t_vector3 *)(ptr[0] + 3)
			);
	}
}

static void				clean_temp(t_mesh_temp *temp)
{
	free(temp->buffer[0]);
	free(temp->buffer[1]);
	free(temp->buffer[2]);
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