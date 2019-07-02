#ifndef MATERIAL_H
# define MATERIAL_H

# include "color.h"

typedef struct 		s_material
{
	t_vector3		color;
	float 	diffuse;
	float 	specular;
	float 	reflect;
	float 	refract;
}					t_material;

t_material			*material_new(t_vector3 color, float diffuse, float specular, float reflect, float refract);

#endif
