#ifndef SHAPE_LIST_H
# define SHAPE_LIST_H

# include "shape.h"

typedef struct		s_shape_data_sphere
{
	t_vector3		center;
	float 			radius;
}					t_shape_data_sphere;

int					shape_intersect_sphere(t_shape *shape, t_intersection *intersection);
t_vector3			shape_random_sphere(t_shape *shape);
t_shape				shape_sphere(t_vector3 center, float radius, t_material material);

typedef struct		s_shape_data_plane
{
	t_vector3		position;
	t_vector3		normal;
}					t_shape_data_plane;

int					shape_intersect_plane(t_shape *shape, t_intersection *intersection);
t_shape				shape_plane(t_vector3 position, t_vector3 normal, t_material material);

typedef struct		s_shape_data_triangle
{
	t_vector3		a;
	t_vector3		b;
	t_vector3		c;
}					t_shape_data_triangle;

int					shape_intersect_triangle(t_shape *shape, t_intersection *intersection);
t_shape				shape_triangle(t_vector3 a, t_vector3 b, t_vector3 c, t_material material);

#endif
