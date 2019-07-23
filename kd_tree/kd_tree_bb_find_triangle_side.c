#include "kd_tree.h"

t_kd_tree_side		kd_tree_bb_find_triangle_side(const t_kd_tree_bb *bb, const t_triangle *triangle, t_kd_tree_axis axis)
{
	float			triangle_middle;

	if (axis == axis_x)
	{
		triangle_middle = (triangle->a.x + triangle->b.x + triangle->c.x) / 3.f;
		return (triangle_middle <= bb->middle.x ? side_left : side_right);
	}
	if (axis == axis_y)
	{
		triangle_middle = (triangle->a.y + triangle->b.y + triangle->c.y) / 3.f;
		return (triangle_middle <= bb->middle.y ? side_left : side_right);

	}
	if (axis == axis_z)
	{
		triangle_middle = (triangle->a.z + triangle->b.z + triangle->c.z) / 3.f;
		return (triangle_middle <= bb->middle.z ? side_left : side_right);
	}
	exit(3);
}