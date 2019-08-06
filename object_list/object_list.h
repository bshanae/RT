#ifndef OBJECT_DATA_H
# define OBJECT_DATA_H

# include "cl_include.h"

typedef struct		s_object_sphere
{
	cl_double4		position;
	double			radius;
}					t_object_sphere;

typedef struct		s_object_plane
{
	cl_double4		position;
	cl_double4		normal;
}					t_object_plane;

#endif
