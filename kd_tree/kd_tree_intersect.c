#include "kd_tree.h"


int 				kd_tree_intersect(t_kd_tree_node *node, t_intersection *intersection)
{
	int 			result;

	if (!node)
		return (0);
	if (!kd_tree_bb_intersect(&node->bb, intersection))
		return (0);
	if (kd_tree_intersect(node->left, intersection))
		return (1);
	if (kd_tree_intersect(node->right, intersection))
		return (1);
	if (!node->left && !node->right)
	{
		result = 0;
		for (int i = 0; i < node->array.length; i++)
			result += triangle_intersect(node->mesh->triangles + node->array.indexes[i], intersection);
		if (result > 1)
			double_intersection = 1;
		return (result);
	}
	return (0);
}