#include "accelerated_mesh.h"

t_accelerated_mesh		*accelerated_mesh_new(const char *file_name, t_material material)
{
	t_accelerated_mesh	*mesh;

	mesh = (t_accelerated_mesh *)malloc(sizeof(t_accelerated_mesh));
	mesh->mesh = mesh_new(file_name, material);
	mesh->kd_tree = kd_tree_build(mesh->mesh);
	return (mesh);
}
