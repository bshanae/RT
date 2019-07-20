#ifndef MATERIAL_H
# define MATERIAL_H

# include "vector3.h"

typedef struct		s_material
{
	t_vector3		color;
	t_vector3		emission;
	float 			reflection;
	float 			refraction;
}					t_material;

#endif
