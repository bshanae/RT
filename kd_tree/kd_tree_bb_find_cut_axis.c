#include "kd_tree.h"

t_kd_tree_axis		kd_tree_bb_find_cut_axis(const t_kd_tree_bb *bb)
{
	float x = fabsf(bb->max.x - bb->min.x);
	float y = fabsf(bb->max.y - bb->min.y);
	float z = fabsf(bb->max.z - bb->min.z);

	if (x >= y && x >= z)
		return (axis_x);
	if (y >= x && y >= z)
		return (axis_y);
	if (z >= x && z >= y)
		return (axis_z);
	exit(3);
}