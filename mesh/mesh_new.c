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

	for (int i = 0; i < temp->attributes.num_face_num_verts; i++)
		for (int f = 0; f < (int)temp->attributes.face_num_verts[i] / 3; f++)
		{
			size_t k;
			t_vector3	v[3];
			float n[3][3];
			float c[3];
			float len2;

			tinyobj_vertex_index_t idx0 = temp->attributes.faces[3 * f + 0];
			tinyobj_vertex_index_t idx1 = temp->attributes.faces[3 * f + 1];
			tinyobj_vertex_index_t idx2 = temp->attributes.faces[3 * f + 2];

			for (k = 0; k < 3; k++)
			{
				int f0 = idx0.v_idx;
				int f1 = idx1.v_idx;
				int f2 = idx2.v_idx;

				v[k].x = temp->attributes.vertices[3 * f0 + k];
				v[k].y = temp->attributes.vertices[3 * f1 + k];
				v[k].z = temp->attributes.vertices[3 * f2 + k];
			}

			printf("{{%f, %f, %f}, {%f, %f, %f}, {%f, %f, %f}}\n",
				v[0].x, v[0].y, v[0].z,
				v[1].x, v[1].y, v[1].z,
				v[2].x, v[2].y, v[2].z);
		}
	exit(2);
}

static void				clean_temp(t_mesh_temp *temp)
{

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