#include "kd_tree.h"

# define DEBUG			0
# define DEPTH			20

static t_kd_tree_node	*build_tree_recursive(const t_mesh *mesh, t_kd_tree_array *array, int depth)
{
	t_kd_tree_node		*node;
	t_kd_tree_array		left;
	t_kd_tree_array		right;
	t_kd_tree_axis		axis;
	float 				median;
	t_kd_tree_side		side;
	int 				error;

	if (depth > DEPTH)
		return (NULL);

	node = kd_tree_node_create(mesh);
	node->array = *array;
	node->bb = kd_tree_bb_create(mesh, array);

	if (array->length < 3)
		return (node);

	left = kd_tree_array_create((int)(array->length * 0.6));
	right = kd_tree_array_create((int)(array->length * 0.6));

	axis = kd_tree_bb_find_cut_axis(&node->bb);
	median = kd_tree_array_find_median(array, mesh, axis);

	error = 0;
	for (int i = 0; i < node->array.length && !error; i++)
	{
		side = kd_tree_bb_find_triangle_side(mesh->triangles + node->array.indexes[i], axis, &median);
		if (side == side_left || side == side_schrodinger)
			error = kd_tree_array_add(&left, node->array.indexes + i);
		if (side == side_right || side == side_schrodinger)
			error = kd_tree_array_add(&right, node->array.indexes + i);
	}
	if (error)
	{
		free(left.indexes);
		free(right.indexes);
		return (node);
	}

	if (left.length)
		node->left = build_tree_recursive(mesh, &left, depth + 1);
	if (right.length)
		node->right = build_tree_recursive(mesh, &right, depth + 1);

	return (node);
}

int 					count(t_kd_tree_node *node)
{
	int 				sum;

	sum = 0;
	if (node->left)
		sum += count(node->left);
	if (node->right)
		sum += count(node->right);
	if (!node->left && !node->right)
		sum += node->array.length;
	return (sum);
}

t_kd_tree_node			*kd_tree_build(const t_mesh *mesh)
{
	t_kd_tree_node		*root;
	t_kd_tree_array		array;

	array = kd_tree_array_create(mesh->triangles_number);
	for (int i = 0; i < mesh->triangles_number; i++)
		kd_tree_array_add(&array, &i);
	root = build_tree_recursive(mesh, &array, 0);
	printf("tree total polygons = %d\n", count(root));
	return (root);
}