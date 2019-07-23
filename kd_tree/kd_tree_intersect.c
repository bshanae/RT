#include "kd_tree.h"

#include <stdio.h>
int recursion_id_i = 0;

int 				kd_tree_intersect(t_kd_tree_node *node, t_intersection *intersection)
{
	int 			result;

	if (!node)
		return (0);
//	printf("id = %d\n", recursion_id_i++);
	if (node->bb.min.x == -INFINITY)
		exit(4);
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
		return (result != 0);
	}
	return (0);
}