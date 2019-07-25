#include "kd_tree.h"

int 				kd_tree_bb_intersect(t_kd_tree_bb *bb, t_intersection *intersection)
{
#define BB_KOSKIV

#ifdef BB_OLD
	float			inv_dir;
	float 			t[2];
	float 			t_near;
	float 			t_far;
	float 			t_temp;
	int 			i;

	i = 0;
	t_near = INTERSECTION_MIN;
	t_far = INTERSECTION_MAX;
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
	if (t_near == INTERSECTION_MIN || t_near >= intersection->ray.t)
		return (0);
	return (1);
#endif

#ifdef BB_KOSKIV
	//If a mesh has no polygons, it won't have a root bbox either.
	if (!bb) return 0;

	t_vector3	dirfrac;
	dirfrac.x = 1.0 / intersection->ray.direction.x;
	dirfrac.y = 1.0 / intersection->ray.direction.y;
	dirfrac.z = 1.0 / intersection->ray.direction.z;

	double t1 = (bb->min.x - intersection->ray.origin.x)*dirfrac.x;
	double t2 = (bb->max.x - intersection->ray.origin.x)*dirfrac.x;
	double t3 = (bb->min.y - intersection->ray.origin.y)*dirfrac.y;
	double t4 = (bb->max.y - intersection->ray.origin.y)*dirfrac.y;
	double t5 = (bb->min.z - intersection->ray.origin.z)*dirfrac.z;
	double t6 = (bb->max.z - intersection->ray.origin.z)*dirfrac.z;

	double tmin = fmaxf(fmaxf(fminf(t1, t2), fminf(t3, t4)), fminf(t5, t6));
	double tmax = fminf(fminf(fmaxf(t1, t2), fmaxf(t3, t4)), fmaxf(t5, t6));

	// if tmax < 0, ray is intersecting AABB, but the whole AABB is behind us
	if (tmax < 0)
		return 0;

	// if tmin > tmax, ray doesn't intersect AABB
	if (tmin > tmax)
		return 0;
	return (1);
#endif
}