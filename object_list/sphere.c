#include "object_interaction.h"

void						object_sphere_build(t_object *space, va_list *args)
{
	t_object_sphere	*data;

	data = (t_object_sphere *)space->data;
	data->position = va_arg(*args, t_vector3);
	data->radius = va_arg(*args, double);
	space->type = object_sphere;
}

int						object_sphere_intersect(t_object *object, t_intersection *intersection)
{
	t_object_sphere		*data;
	double				k[3];
	double				t;
	double				discriminant;
	t_vector3			temp;

	data = (t_object_sphere *)object->data;
	temp = vector3_sub_ref(&intersection->ray.origin, &data->position);
	k[0] = 1.;
	k[1] = 2 * vector3_dot_ref(&temp, &intersection->ray.direction);
	k[2] = vector3_dot_ref(&temp, &temp) - data->radius * data->radius;
	discriminant = k[1] * k[1] - 4 * k[0] * k[2];
	if (discriminant < 0.)
		return (0);
	t = (-k[1] - sqrt(discriminant)) / 2;
	if (t <= INTERSECTION_MIN || t >= intersection->ray.t)
		return (0);
	intersection->ray.t = t;
//	temp = ray_calculate(&intersection->ray);
//	intersection->normal = vector3_sub_ref(&temp, &data->center);
//	vector3_normalize(&intersection->normal);
//	intersection->hit = temp;
//	intersection->material = object->material;
	return (1);
}