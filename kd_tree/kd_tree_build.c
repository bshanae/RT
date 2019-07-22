#include "kd_tree.h"

static t_kd_tree_node	*build_tree_recursive(t_mesh *mesh, t_kd_tree_array *array)
{
	t_kd_tree_node		*node;

	node = build_node();
	node->array = *array;

	// exit condition ?


}

t_kd_tree_node			*kd_tree_build(t_mesh *mesh)
{
	t_kd_tree_node		*root;
	t_kd_tree_array		array;

	array = build_array(mesh->triangles_number);
	root = build_tree_recursive(mesh, &array);
}