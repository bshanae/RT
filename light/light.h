#ifndef LIGHT_H
# define LIGHT_H

# include "vector3.h"

typedef struct 		s_light
{
	t_vector3		position;
	float 			intensity;
}					t_light;

#endif
