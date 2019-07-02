#include "shape_list.h"

void					shape_delete(t_shape **me)
{
	free((*me)->data);
	free(*me);
	*me = NULL;
}

t_intersection_function	shape_get_function_ptr(int i)
{
	static t_intersection_function	array[SHAPE_TYPE_NUM];

	if (!array[0])
	{
		array[0] = sphere_intersect;
		array[1] = plane_intersect;
		array[2] = cylinder_intersect;
		array[3] = aabb_intersect;
		array[4] = cone_intersect;
		array[5] = disk_intersect;
	}
	if (i < 0 || i >= SHAPE_TYPE_NUM)
		return (NULL);
	return (array[i]);
}

int 						shape_find_function_ptr(t_intersection_function ptr)
{
	int 					i;

	i = 0;
	while(i < SHAPE_TYPE_NUM)
	{
		if (shape_get_function_ptr(i) == ptr)
			return (i);
		i++;
	}
	return (-1);
}