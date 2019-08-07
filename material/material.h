#ifndef MATERIAL_H
# define MATERIAL_H

# include "cl_include.h"
# include "cl_float.h"

typedef struct 		s_material
{
	API_FLOAT4		color;
	API_FLOAT4		emission;
}					t_material;

#endif
