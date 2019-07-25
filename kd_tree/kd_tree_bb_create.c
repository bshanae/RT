#include "kd_tree.h"

t_kd_tree_bb				kd_tree_bb_create(const t_mesh *mesh, t_kd_tree_array *array)
{
	t_kd_tree_bb			bb;
	t_vector3				*ptr;

	bb.min = (t_vector3){INFINITY, INFINITY, INFINITY};
	bb.max = (t_vector3){-INFINITY, -INFINITY, -INFINITY};
	for (int i = 0; i < array->length; i++)
	{
		ptr = &mesh->triangles[array->indexes[i]].a;
		for (int j = 0; j < 3; j++)
		{
			bb.min = vector3_min_vector(&bb.min, ptr);
			bb.max = vector3_max_vector(&bb.max, ptr);
			ptr++;
		}
	}
	return (bb);
}