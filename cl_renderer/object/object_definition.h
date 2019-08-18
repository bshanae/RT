#ifndef OBJECT_H
# define OBJECT_H

# include "rt_parameters.h"
# include "material.h"

typedef enum		e_object_type
{
	object_light_point,
	object_light_direct,
	object_sphere,
	object_plane,
    object_cone,
    object_cylinder,
    object_aabb,
	object_end
}					t_object_type;

typedef struct		s_object
{
	char 			name[32];
	int				id;
	t_object_type	type;
	t_material		material;
	char			data[RT_CL_OBJECT_DATA_CAPACITY];
}					t_object;

const char 			*object_translate(t_object_type type);

#endif
