#include "shape_moebius.h"

int						double_sign(double x)
{
	if (x < -EPSILON)
		return (-1);
	return (x > EPSILON);
}

int						inside_moebius_strip(t_moebius *m, t_vector3 hit)
{
	double				t;
	double				s;

	t = atan2(hit.y, hit.x);
	if (double_sign(sin(t / 2)) != 0)
		s = hit.z / sin(t / 2);
	else
		s = double_sign(cos(t)) ?
			(hit.x / cos(t) - m->radius) / cos(t / 2) :
			(hit.y / sin(t) - m->radius) / cos(t / 2);
	hit.x -= (m->radius + s * cos(t / 2)) * cos(t);
	hit.y -= (m->radius + s * cos(t / 2)) * sin(t);
	hit.z -= s * sin(t / 2);
	if (double_sign(hit.x * hit.x + hit.y * hit.y + hit.z * hit.z))
		return (0);
	return (s >= -m->max && s <= m->max);
}

static double			choose_equation_root(double *roots, int result, t_ray *ray, t_moebius *data)
{
	int					i;
	t_vector3			hit;

	i = 0;
	while (i < result)
	{
		if (roots[i] > -1.)
		{
			hit = vector3_s_add(vector3_s_mul(ray->direction, roots[i]), ray->origin);
			if (inside_moebius_strip(data, hit))
				return (roots[i]);
		}
		i++;
	}
	return (INFINITY);
}

static void				init_coefficients(t_moebius *m, double *coefficient)
{

	coefficient[0] = (m->ox * m->ox * m->oy + m->oy * m->oy * m->oy - 2 * m->ox * m->ox * m->oz
			- 2 * m->oy * m->oy * m->oz + m->oy * m->oz * m->oz - 2 * m->ox * m->oz * m->radius - m->oy * m->radius * m->radius);
	coefficient[1] = (m->dy * m->ox * m->ox - 2 * m->dz * m->ox * m->ox + 2 * m->dx * m->ox * m->oy
			+ 3 * m->dy * m->oy * m->oy - 2 * m->dz * m->oy * m->oy - 4 * m->dx * m->ox * m->oz - 4 * m->dy * m->oy * m->oz
				+ 2 * m->dz * m->oy * m->oz + m->dy * m->oz * m->oz - 2 * m->dz * m->ox * m->radius - 2 * m->dx * m->oz * m->radius -
				m->dy * m->radius * m->radius);
	coefficient[2] = (2 * m->dx * m->dy * m->ox - 4 * m->dx * m->dz * m->ox + m->dx * m->dx * m->oy
			+ 3 * m->dy * m->dy * m->oy - 4 * m->dy * m->dz * m->oy + m->dz * m->dz * m->oy - 2 * m->dx * m->dx * m->oz
			- 2 * m->dy * m->dy * m->oz + 2 * m->dy * m->dz * m->oz - 2 * m->dx * m->dz * m->radius);
	coefficient[3] = m->dx * m->dx * m->dy + m->dy * m->dy * m->dy - 2 * m->dx * m->dx * m->dz - 2 * m->dy * m->dy * m->dz + m->dy * m->dz * m->dz;
	coefficient[0] /= coefficient[3];
	coefficient[1] /= coefficient[3];
	coefficient[2] /= coefficient[3];
}

double						calculate_moebius_t(t_ray *ray, t_shape_data_moebius *data, t_moebius *moebius)
{
	double					coefficient[4];
	double					root[3];
	int						result;

	moebius->radius = data->radius;
	moebius->ox = ray->origin.x;
	moebius->dx = ray->direction.x;
	moebius->oy = ray->origin.y;
	moebius->dy = ray->direction.y;
	moebius->oz = ray->origin.z;
	moebius->dz = ray->direction.z;
	moebius->max = data->half_width;
	init_coefficients(moebius, coefficient);
	result = solve_moebius_equation(coefficient, root);
	return (choose_equation_root(root, result, ray, moebius));
}

t_vector3					calculate_moebius_normal(t_vector3 *real, t_moebius *obj)
{
	t_vector3				ret;

	ret.x = -2 * obj->radius * real->z + 2 * real->x * real->y - 4 * real->x * real->z;
	ret.y = -obj->radius * obj->radius + real->x * real->x + 3 * real->y * real->y - 4
																				   * real->y * real->z + real->z * real->z;
	ret.z = -2 * obj->radius * real->x - 2 * real->x * real->x - 2 * real->y *
																real->y + 2 * real->y * real->z;
	return (ret);
}

int							moebius_intersect(t_shape *shape, t_intersection *intersection)
{
	t_shape_data_moebius	*data;
	t_moebius				moebius_strip;
	double 					t;

	data = (t_shape_data_moebius *)shape->data;
	t = calculate_moebius_t(&intersection->ray, data, &moebius_strip);
	if (t == INFINITY)
		return (0);
	intersection->ray.t = t;
	t_vector3 p = vector3_s_add(intersection->ray.origin, vector3_mul(&intersection->ray.direction, t));
	p = vector3_sub(&p, &data->position);
	intersection->normal = calculate_moebius_normal(&p, &moebius_strip);
	vector3_normalize(&intersection->normal);
	intersection->material = shape->material;
	intersection->color = shape->material->color;
	intersection->highlight = &shape->highlight;
	return (1);
}

t_shape						*shape_moebius(double radius, double max, t_vector3 position, t_material *material)
{
	t_shape					*shape;
	t_shape_data_moebius	*data;

	if (!(shape = (t_shape *)malloc(sizeof(t_shape))))
		exit(21);
	if (!(data = (t_shape_data_moebius *)malloc(sizeof(t_shape_data_moebius))))
		exit(21);
	data->radius = radius;
	data->half_width = max;
	data->position = position;
	shape->material = material;
	shape->data = (void *)data;
	shape->data_size = sizeof(t_shape_data_moebius);
	shape->intersect = moebius_intersect;
	shape->highlight = 0;
	return (shape);
}