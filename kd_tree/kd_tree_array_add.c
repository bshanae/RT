#include "kd_tree.h"

int				kd_tree_array_add(t_kd_tree_array *array, INT_REF value)
{
	if (array->length == array->capacity)
		return (1);
	array->indexes[array->length++] = *value;
	return (0);
}