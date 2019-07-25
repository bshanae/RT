#include "kd_tree.h"

t_kd_tree_side		kd_tree_bb_find_triangle_side(const t_triangle *triangle, t_kd_tree_axis axis, const float *median)
{
	if (*vector3_iter(&triangle->min, axis) < *median && *vector3_iter(&triangle->max, axis) < *median)
		return (side_left);
	else if (*vector3_iter(&triangle->min, axis) > *median && *vector3_iter(&triangle->max, axis) > *median)
		return (side_right);
	else if (*vector3_iter(&triangle->min, axis) < *median && *vector3_iter(&triangle->max, axis) > *median)
		return (side_schrodinger);
	exit(111);
}