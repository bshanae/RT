#include "kd_tree.h"

int 				kd_tree_intersect(t_kd_tree_node *node, t_intersection *intersection)
{
	int 			result;
	int 			hit_left;
	int 			hit_right;

	if (!node)
		return (0);
	if (!kd_tree_bb_intersect(&node->bb, intersection))
		return (0);
	if (node->left || node->right)
	{
		hit_right = kd_tree_intersect(node->right, intersection);
		hit_left = kd_tree_intersect(node->left, intersection);
		return (hit_left || hit_right);
	}
	if (!node->left && !node->right)
	{
		result = 0;
		for (int i = 0; i < node->array.length; i++)
			result += triangle_intersect(node->mesh->triangles + node->array.indexes[i], intersection);
		if (result)
			return (result);
	}
	return (0);
}