#ifndef ACCELERATED_MESH_H
# define ACCELERATED_MESH_H

# include "mesh.h"
# include "kd_tree.h"

typedef struct 		s_accelerated_mesh
{
	t_mesh			*mesh;
	t_kd_tree_node	*kd_tree;
}					t_accelerated_mesh;

t_accelerated_mesh	*accelerated_mesh_new(const char *file_name, t_material material);

void 				accelerated_mesh_delete(t_accelerated_mesh **mesh);

#endif
