#include "kd_tree.h"

void				kd_tree_destroy(t_kd_tree_node **node)
{
	if (!(*node))
		return ;
	kd_tree_destroy(&(*node)->left);
	kd_tree_destroy(&(*node)->right);
	free((*node)->array.indexes);
	free(*node);
	*node = NULL;
}