#include "shape_list.h"

void				sphere_move(t_shape *shape, t_vector3 move)
{
	t_sphere_data	*data;

	data = (t_sphere_data *)shape->data;
	vector3_add_eq(&data->center, &move);
}

t_shape				shape_sphere
	(t_vector3 center, float radius, t_material material)
{
	t_shape			shape;
	t_sphere_data	*data;

	shape.id = SHAPE_ID_SPHERE;
	data = (t_sphere_data *)shape.data;
	data->center = center;
	data->radius = radius;
	shape.material = material;
	shape.highlight = 0;
	return (shape);
}