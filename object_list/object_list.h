#ifndef OBJECT_DATA_H
# define OBJECT_DATA_H

# include "vector3.h"

typedef struct		s_object_sphere
{
	t_vector3		position;
	double			radius;
}					t_object_sphere;

typedef struct		s_object_plane
{
	t_vector3		position;
	t_vector3		normal;
}					t_object_plane;

#endif
