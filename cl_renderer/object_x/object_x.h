#ifndef OBJECT_DATA_H
# define OBJECT_DATA_H

# include "rt_cl_include.h"
# include "rt_float.h"

typedef struct		s_object_light_ambient
{
}					t_object_light_ambient;

typedef struct		s_object_light_point
{
	RT_F4_API		position;
}					t_object_light_point;

typedef struct		s_object_light_direct
{
	RT_F4_API		direction;
}					t_object_light_direct;

typedef struct		s_object_sphere
{
	RT_F4_API		position;
	RT_F			radius;
}					t_object_sphere;

typedef struct		s_object_plane
{
	RT_F4_API		position;
	RT_F4_API		normal;
}					t_object_plane;

typedef struct 		s_object_cone
{
	RT_F4_API		top;
	RT_F4_API		bottom;
	RT_F4_API		axis;
	RT_F 			radius;
	RT_F          	tangent;
}					t_object_cone;

typedef struct 		s_object_cylinder
{
	RT_F4_API		top;
	RT_F4_API		bottom;
	RT_F4_API		axis;
	RT_F 			radius;
}					t_object_cylinder;

typedef struct 		s_object_box
{
	RT_F4_API  		position;
	RT_F4_API  		size;
}					t_object_box;

typedef struct 		s_object_paraboloid
{
	RT_F4_API		extremum;
	RT_F4_API		axis;
	RT_F 			radius;
}					t_object_paraboloid;

typedef struct		s_object_moebius
{
	RT_F4_API		position;
	RT_F 			radius;
	RT_F			half_width;
}					t_object_moebius;

typedef struct 		s_object_torus
{
	RT_F4_API  		position;
	RT_F 			t_0;
	RT_F          	t_1;
}					t_object_torus;

typedef struct		s_object_tetrahedron
{
	int				iterations;
	RT_F			scale;
}					t_object_tetrahedron;

typedef struct		s_object_mandelbulb
{
	int				iterations;
	RT_F			power;
	RT_F			bailout;
}					t_object_mandelbulb;

typedef struct		s_object_julia
{
	int				iterations;
	RT_F4_API		value;
}					t_object_julia;

#endif
