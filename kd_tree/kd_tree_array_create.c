#include "kd_tree.h"

t_kd_tree_array		kd_tree_array_create(int capacity)
{
	t_kd_tree_array	array;

	array.length = 0;
	array.capacity = capacity;
	array.indexes = (int *)malloc(sizeof(int) * capacity);
	return (array);
}