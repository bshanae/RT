#include "mesh.h"

/*
Faces:
	2/0/1	4/0/1	1/0/1
	8/0/2	6/0/2	5/0/2
	5/0/3	2/0/3	1/0/3
	6/0/4	3/0/4	2/0/4
	3/0/5	8/0/5	4/0/5
	1/0/6	8/0/6	5/0/6
	2/0/1	3/0/1	4/0/1
	8/0/2	7/0/2	6/0/2
	5/0/3	6/0/3	2/0/3
	6/0/4	7/0/4	3/0/4
	3/0/5	7/0/5	8/0/5
	1/0/6	4/0/6	8/0/6
 */

static void				read_data(t_mesh_temp *temp, const char *file_name)
{
	u_long 				file_size;

	temp->buffer[0] = open_file(file_name, &file_size);
	temp->buffer[1] = malloc(objpar_get_size(temp->buffer[0], file_size));
	objpar((const char *)temp->buffer[0], file_size, temp->buffer[1], &temp->obj);
}

static void				get_mesh(t_mesh *mesh, t_mesh_temp *temp, const t_material *material)
{
	u_int 				vertex_index[3];

	if (temp->obj.face_width != 3)
		exit(21);
	mesh->triangles = (t_shape *)malloc(sizeof(t_shape) * temp->obj.face_count);
	mesh->triangles_number = 0;

	for (int i = 0; i < temp->obj.face_count * temp->obj.face_width * 3; i += temp->obj.face_width * 3)
	{
		for (int j = 0; j < temp->obj.face_width * 3; j += 3)
			vertex_index[j / 3] = 3 * (temp->obj.p_faces[i + j + OBJPAR_V_IDX] - 1);

		mesh->triangles[mesh->triangles_number++] = shape_triangle
			(
				*(t_vector3 *)(temp->obj.p_positions + vertex_index[0]),
				*(t_vector3 *)(temp->obj.p_positions + vertex_index[1]),
				*(t_vector3 *)(temp->obj.p_positions + vertex_index[2]),
				*material
			);
	}
}

static void				clean_temp(t_mesh_temp *temp)
{
	free(temp->buffer[0]);
	free(temp->buffer[1]);
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