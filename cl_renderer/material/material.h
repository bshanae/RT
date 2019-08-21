#ifndef MATERIAL_H
# define MATERIAL_H

# include "rt_cl_include.h"
# include "rt_float.h"

typedef struct 		s_material
{
	RT_F4_API		color;
	RT_F4_API		emission;
	RT_F			reflection;
	RT_F			refraction;
}					t_material;

#endif
