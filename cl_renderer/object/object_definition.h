#ifndef OBJECT_H
# define OBJECT_H

# include "rt_parameters.h"
# include "material.h"

typedef enum		e_object_type
{
	object_light_ambient,
	object_light_point,
	object_light_direct,
	object_sphere,
	object_plane,
	object_cone,
	object_cylinder,
	object_box,
	object_paraboloid,
	object_moebius,
	object_torus,
	object_mandelbulb,
	object_julia,
	object_csg,
	object_perforated_cube,
	object_end
}					t_object_type;

typedef struct		s_object
{
	char 			name[32];
	int				id;
	t_object_type	type;
	int 			is_csg;
	t_material		material;
	int 			texture_id;
	char			data[RT_CL_OBJECT_CAPACITY];
}					t_object;

const char 			*object_translate(t_object_type type);

#endif
