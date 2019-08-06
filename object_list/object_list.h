#ifndef OBJECT_DATA_H
# define OBJECT_DATA_H

# include "cl_include.h"
# include "cl_float.h"

typedef struct		s_object_sphere
{
	API_FLOAT4		position;
	FLOAT			radius;
}					t_object_sphere;

typedef struct		s_object_plane
{
	API_FLOAT4		position;
	API_FLOAT4		normal;
}					t_object_plane;

#endif
