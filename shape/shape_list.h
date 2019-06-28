#ifndef SHAPE_LIST_H
# define SHAPE_LIST_H

# include "libft_standart.h"

# include "vector3.h"
# include "shape.h"

/*
********************************************************************************
**						SPHERE
********************************************************************************
*/

typedef struct 			s_sphere_data
{
	t_vector3			center;
	float 				radius;
}						t_sphere_data;

int						sphere_intersect
	(t_shape *shape, t_intersection *intersection);

t_shape					*shape_sphere
	(t_vector3 center, float radius, const t_material *material);

/*
********************************************************************************
**						PLANE
********************************************************************************
*/

typedef struct 			s_plane_data
{
	t_vector3			position;
	t_vector3			normal;
}						t_plane_data;

int 					plane_intersect
	(t_shape *shape, t_intersection *intersection);

t_shape					*shape_plane
	(t_vector3 position, t_vector3 normal, const t_material *material);

/*
********************************************************************************
**						CYLINDER
********************************************************************************
*/

typedef struct 			s_cylinder_data
{
	t_vector3			top;
	t_vector3			bottom;
	float 				radius;
	t_vector3			axis;
}						t_cylinder_data;

int 					cylinder_intersect
	(t_shape *shape, t_intersection *intersection);

t_shape					*shape_cylinder
	(t_vector3 top, t_vector3 bottom, float radius, const t_material *material);

/*
********************************************************************************
**						AABB
********************************************************************************
*/

typedef struct 			s_aabb_data
{
	t_vector3			min;
	t_vector3			max;
}						t_aabb_data;

int 					aabb_intersect
	(t_shape *shape, t_intersection *intersection);

t_shape					*shape_aabb
	(t_vector3 min, t_vector3 max, t_material *material);

/*
********************************************************************************
**						CONE
********************************************************************************
*/

typedef struct 			s_cone_data
{
	t_vector3			top;
	t_vector3			bottom;
	float 				radius;
	float          	tangens;
	t_vector3			axis;
}						t_cone_data;

int 					cone_intersect
		(t_shape *shape, t_intersection *intersection);

t_shape					*shape_cone
	 (t_vector3 top, t_vector3 bottom, float tangens, const t_material *material);

/*
********************************************************************************
**						DISK
********************************************************************************
*/

typedef struct 			s_disk_data
{
	t_vector3			position;
	t_vector3			normal;
	float 				radius;
}						t_disk_data;

int 					disk_intersect(t_shape *shape, t_intersection *intersection);

t_shape					*shape_disk
	(t_vector3 position, t_vector3 normal, float radius, const t_material *material);

/*
********************************************************************************
**						STUFF
********************************************************************************
*/

# define SHAPE_TYPE_NUM	6
# define SHAPE_SIZE_MAX	sizeof(t_cone_data)

typedef int(*t_intersection_function)(struct s_shape *, t_intersection *);

typedef int(*t_intersection_function_cl)(struct s_shape_cl *,void *, t_intersection_cl *);

t_intersection_function	shape_get_function_ptr(int i);

int 					shape_find_function_ptr(t_intersection_function ptr);



#endif
