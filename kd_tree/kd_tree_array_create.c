#include "kd_tree.h"

t_kd_tree_array		kd_tree_array_create(int length)
{
	t_kd_tree_array	array;

	array.length = length;
	array.polygons = (int *)malloc(sizeof(int) * length);
	return (array);
}