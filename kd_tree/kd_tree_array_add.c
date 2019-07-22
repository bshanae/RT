#include "kd_tree.h"

void				kd_tree_array_add(t_kd_tree_array *array, INT_REF value)
{
	if (array->length == array->capacity)
		exit(3);
	array->indexes[array->length++] = *value;
}