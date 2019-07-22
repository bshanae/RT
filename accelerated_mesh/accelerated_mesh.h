#ifndef MESH_H
# define MESH_H

# include "mesh.h"
# include "kd_tree.h"

typedef struct 		s_accelerated_mesh
{
	t_mesh			*mesh;
	t_kd_tree_node	*kd_tree;
}					t_accelerated_mesh;

#endif
