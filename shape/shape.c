#include "shape_list.h"

int					shape_intersect(t_shape *shape, t_intersection *intersection)
{
	if (shape->id == SHAPE_ID_SPHERE)
		return (shape_intersect_sphere(shape, intersection));
	else if (shape->id == SHAPE_ID_PLANE)
		return (shape_intersect_plane(shape, intersection));
	exit(2);
}