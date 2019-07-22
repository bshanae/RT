#include "kd_tree.h"

static t_kd_tree_node	*build_tree_recursive(const t_mesh *mesh, t_kd_tree_array *array, int depth)
{
	t_kd_tree_node		*node;
	t_kd_tree_array		left;
	t_kd_tree_array		right;
	t_kd_tree_axis		axis;

	node = kd_tree_node_create();
	node->array = *array;

	if (depth > 16)
		return (node);

	if (array->length < 2)
		return (node);

	node->bb = kd_tree_bb_create(mesh, array);
	left = kd_tree_array_create(array->length);
	right = kd_tree_array_create(array->length);

	axis = kd_tree_bb_find_cut_axis(&node->bb);

	for (int i = 0; i < node->array.length; i++)
		if (kd_tree_bb_find_triangle_side(&node->bb, mesh->triangles + node->array.indexes[i], axis) == side_left)
			kd_tree_array_add(&left, node->array.indexes + i);
		else
			kd_tree_array_add(&right, node->array.indexes + i);

	if (left.length)
		node->left = build_tree_recursive(mesh, &left, depth + 1);
	if (right.length)
		node->right = build_tree_recursive(mesh, &right, depth + 1);

	return (node);
}

t_kd_tree_node			*kd_tree_build(const t_mesh *mesh)
{
	t_kd_tree_node		*root;
	t_kd_tree_array		array;

	array = kd_tree_array_create(mesh->triangles_number);
	for (int i = 0; i < mesh->triangles_number; i++)
		array.indexes[i] = i;
	root = build_tree_recursive(mesh, &array, 0);
	return (root);
}