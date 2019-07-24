#include "kd_tree.h"

t_kd_tree_node		*kd_tree_node_create(const t_mesh *mesh)
{
	t_kd_tree_node	*node;

	node = (t_kd_tree_node *)malloc_guard(sizeof(t_kd_tree_node));
	node->array.capacity = -1;
	node->left = NULL;
	node->right = NULL;
	node->mesh = mesh;
	return (node);
}