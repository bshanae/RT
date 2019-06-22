#ifndef MATERIAL_H
# define MATERIAL_H

# include "color.h"

typedef struct 		s_material
{
	t_vector3		color;
	FLOAT_MACRO 	diffuse;
	FLOAT_MACRO 	specular;
	FLOAT_MACRO 	reflect;
	FLOAT_MACRO 	refract;
}					t_material;

t_material			*material_new(t_vector3 color, FLOAT_MACRO diffuse, FLOAT_MACRO specular, FLOAT_MACRO reflect, FLOAT_MACRO refract);

#endif
