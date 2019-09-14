#ifndef OBJECT_DATA_H
# define OBJECT_DATA_H

# include "rt_cl_include.h"
# include "rt_float.h"

typedef struct			s_object_light_ambient
{
}						t_object_light_ambient;

typedef struct			s_object_light_point
{
	RT_F4_API			position;
}						t_object_light_point;

typedef struct			s_object_light_direct
{
	RT_F4_API			direction;
}						t_object_light_direct;

typedef struct			s_object_sphere
{
	RT_F4_API			position;
	RT_F				radius;
}						t_object_sphere;

typedef enum 			e_plane_limiting
{
	plane_limiting_yes,
	plane_limiting_no
}						t_plane_limiting;

typedef struct			s_object_plane
{
	RT_F4_API			position;
	RT_F4_API			normal;
	t_plane_limiting	is_limiting;
}						t_object_plane;

typedef struct 			s_object_cone
{
	RT_F4_API			top;
	RT_F4_API			bottom;
	RT_F4_API			axis;
	RT_F 				radius;
	RT_F          		tangent;
}						t_object_cone;

typedef struct 			s_object_cylinder
{
	RT_F4_API			top;
	RT_F4_API			bottom;
	RT_F4_API			axis;
	RT_F 				radius;
}						t_object_cylinder;

typedef struct 			s_object_box
{
	RT_F4_API  			position;
	RT_F4_API  			size;
}						t_object_box;

typedef struct 			s_object_paraboloid
{
	RT_F4_API			extremum;
	RT_F4_API			axis;
	RT_F 				radius;
}						t_object_paraboloid;

typedef struct			s_object_moebius
{
	RT_F4_API			position;
	RT_F 				radius;
	RT_F				half_width;
}						t_object_moebius;

typedef struct 			s_object_limited
{
	int     			main_id;
	int     			limit_id;
	char 				main_name[64];
	char    			limit_name[64];
}						t_object_limited;

typedef struct 			s_object_torus
{
	RT_F4_API  			position;
	RT_F 				t_0;
	RT_F          		t_1;
}						t_object_torus;

typedef struct			s_object_mandelbulb
{
	RT_F4_API			position;
	int					iterations;
	RT_F				power;
}						t_object_mandelbulb;

typedef struct			s_object_julia
{
	RT_F4_API  			position;
	int					iterations;
	RT_F4_API			value;
}						t_object_julia;

typedef struct			s_object_perforated_cube
{
	RT_F4_API			position;
	int					iterations;
}						t_object_perforated_cube;


typedef struct			s_object_explosion
{
	RT_F4_API			position;
	RT_F				radius;
	RT_F				noise_amplitude;
}						t_object_explosion;

typedef struct 			s_object_csg
{
	int     			positive_id;
	int     			negative_id;
	char 				positive_name[RT_CL_OBJECT_NAME_SIZE];
	char    			negative_name[RT_CL_OBJECT_NAME_SIZE];
}						t_object_csg;

typedef struct 			s_object_pair
{
	int 				first_id;
	int 				second_id;
	char 				first_name[RT_CL_OBJECT_NAME_SIZE];
	char 				second_name[RT_CL_OBJECT_NAME_SIZE];
}						t_object_pair;

#endif
