#ifndef MATERIAL_H
# define MATERIAL_H

# include "color.h"

typedef struct 		s_material
{
	t_vector3		color;
	double 	diffuse;
	double 	specular;
	double 	reflect;
	double 	refract;
}					t_material;

t_material			*material_new(t_vector3 color, double diffuse, double specular, double reflect, double refract);

#endif
