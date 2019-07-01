#include "shape_list.h"

void				plane_move(t_shape *shape, t_vector3 move)
{
	t_plane_data	*data;

	data = (t_plane_data *)shape->data;
	vector3_add_eq(&data->position, &move);
}

t_shape				shape_plane
	(t_vector3 position, t_vector3 normal, t_material material)
{
	t_shape			shape;
	t_plane_data	*data;

	shape.id = SHAPE_ID_PLANE;
	data = (t_plane_data *)shape.data;
	data->position = position;
	data->normal = vector3_normalized(&normal);
	shape.material = material;
	shape.highlight = 0;
	return (shape);
}