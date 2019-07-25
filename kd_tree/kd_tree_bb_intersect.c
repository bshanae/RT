#include "kd_tree.h"

int 				kd_tree_bb_intersect(t_kd_tree_bb *bb, t_intersection *intersection)
{
	float			inv_dir;
	float 			t[2];
	float 			t_near;
	float 			t_far;
	float 			t_temp;
	int 			i;

	i = 0;
	t_near = -INFINITY;
	t_far = INFINITY;
	while (i < 3)
	{
		inv_dir = 1. / *vector3_iter(&intersection->ray.direction, i);
		t[0] = (*vector3_iter(&bb->min, i) - *vector3_iter(&intersection->ray.origin, i)) * inv_dir;
		t[1] = (*vector3_iter(&bb->max, i) - *vector3_iter(&intersection->ray.origin, i)) * inv_dir;
		if (inv_dir < 0.)
		{
			t_temp = t[0];
			t[0] = t[1];
			t[1] = t_temp;
		}
		t_near = fmaxf(t[0], t_near);
		t_far = fminf(t[1], t_far);
		if (t_far <= t_near)
			return (0);
		i++;
	}
	if (t_near == -INFINITY || t_near >= intersection->ray.t)
		return (0);
	return (1);
}