#include "shape_list.h"

void				shape_move(t_shape *shape, t_vector3 step)
{
	if (shape->id == SHAPE_ID_SPHERE)
		sphere_move(shape, step);
	else if (shape->id == SHAPE_ID_PLANE)
		plane_move(shape, step);
	else if (shape->id == SHAPE_ID_CYLINDER)
		cylinder_move(shape, step);
	else if (shape->id == SHAPE_ID_CONE)
		cone_move(shape, step);
	else if (shape->id == SHAPE_ID_AABB)
		aabb_move(shape, step);
}