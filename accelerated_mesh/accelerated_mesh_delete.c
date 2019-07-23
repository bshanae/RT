#include "accelerated_mesh.h"

void 				accelerated_mesh_delete(t_accelerated_mesh **mesh)
{
	mesh_delete(&(*mesh)->mesh);
	kd_tree_destroy(&(*mesh)->kd_tree);
	free(*mesh);
	*mesh = NULL;
}