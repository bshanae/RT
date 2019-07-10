#include "shape_list.h"

int						shape_intersect_sphere(t_shape *shape, t_intersection *intersection)
{
	t_shape_data_sphere	*data;
	float				k[3];
	float				t;
	float				discriminant;
	t_vector3			temp;

	data = (t_shape_data_sphere *)shape->data;
	k[0] = vector3_dot_ref(&intersection->direction, &intersection->direction);
	temp = vector3_sub_ref(&intersection->origin, &data->center);
	k[1] = 2 * vector3_dot_ref(&temp, &intersection->direction);
	k[2] = vector3_dot_ref(&temp, &temp) - data->radius * data->radius;
	discriminant = k[1] * k[1] - 4 * k[0] * k[2];
	if (discriminant < 0.)
		return (0);
	t = (-k[1] - sqrtf(discriminant)) / (2 * k[0]);
	if (t <= INTERSECTION_MIN || t >= intersection->t)
		return (0);
	intersection->t = t;
	temp = intersection_calculate(intersection);
	intersection->normal = vector3_sub_ref(&temp, &data->center);
	vector3_normalize(&intersection->normal);
	intersection->hit = temp;
	intersection->material = shape->material;
	return (1);
}

t_vector3				shape_random_sphere(t_shape *shape)
{
	t_shape_data_sphere	*data;
	float 				theta;
	float 				phi;
	t_vector3			random;

	data = (t_shape_data_sphere *)shape->data;
	theta = drand48() * M_PI;
	phi = drand48() * 2 * M_PI;
	random.x = 0.99 * data->radius * sinf(theta) * cosf(phi);
	random.y = 0.99 * data->radius * sinf(theta) * sinf(phi);
	random.z = 0.99 * data->radius * cosf(theta);
	vector3_add_eq_ref(&random, &data->center);
	return (random);
}

t_shape					shape_sphere(t_vector3 center, float radius, t_material material)
{
	t_shape				shape;
	t_shape_data_sphere	*data;

	data = (t_shape_data_sphere *)shape.data;
	data->radius = radius;
	data->center = center;
	shape.id = SHAPE_ID_SPHERE;
	shape.material = material;
	return (shape);
}