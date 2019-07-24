#include "kd_tree.h"

#include <stdio.h>

int recursion_id;

# define DEBUG			1

static t_kd_tree_node	*build_tree_recursive(const t_mesh *mesh, t_kd_tree_array *array, int depth)
{
	t_kd_tree_node		*node;
	t_kd_tree_array		left;
	t_kd_tree_array		right;
	t_kd_tree_axis		axis;
	float 				median;

	if (DEBUG) printf("recursion id = %d, depth = %d\n", recursion_id++, depth);

//	if (depth > 2000)
//		return (NULL);



	node = kd_tree_node_create(mesh);
	node->array = *array;

	if (array->length < 2)
		return (node);

	node->bb = kd_tree_bb_create(mesh, array);
	left = kd_tree_array_create(array->length);
	right = kd_tree_array_create(array->length);

	axis = kd_tree_bb_find_cut_axis(&node->bb);
	median = kd_tree_array_find_median(array, mesh, axis);

	for (int i = 0; i < node->array.length; i++)
		if (kd_tree_bb_find_triangle_side(mesh->triangles + node->array.indexes[i], axis, &median) == side_left)
			kd_tree_array_add(&left, node->array.indexes + i);
		else
			kd_tree_array_add(&right, node->array.indexes + i);

	if (DEBUG && left.length == 2)
		printf("bb : {%f, %f, %f} -> {%f, %f, %f}, median for %s axis = %f, left array[%d], right array[%d]\n",
			   node->bb.min.x, node->bb.min.y, node->bb.min.z,
			   node->bb.max.x, node->bb.max.y, node->bb.max.z,
			   axis == axis_x ? "x" : axis == axis_y ? "y" : "z",
			   median,
			   left.length,
			   right.length);

	if (left.length)
	{
		if (DEBUG)
			printf("left child : %d elements\n", left.length);
		node->left = build_tree_recursive(mesh, &left, depth + 1);
	}
	if (right.length)
	{
		if (DEBUG)
			printf("right child\n");
		node->right = build_tree_recursive(mesh, &right, depth + 1);
	}

	return (node);
}

t_kd_tree_node			*kd_tree_build(const t_mesh *mesh)
{
	t_kd_tree_node		*root;
	t_kd_tree_array		array;

	recursion_id = 0;
	array = kd_tree_array_create(mesh->triangles_number);
	for (int i = 0; i < mesh->triangles_number; i++)
		kd_tree_array_add(&array, &i);
	root = build_tree_recursive(mesh, &array, 0);
	return (root);
}