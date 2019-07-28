#ifndef LIGHT_H
# define LIGHT_H

# include "vector3.h"

# include <stdarg.h>

typedef enum		e_light_type
{
	light_ambient,
	light_point,
	light_directional
}					t_light_type;

typedef	struct 		s_light
{
	t_light_type	type;
	double		intensity;
	t_vector3		vector;
}					t_light;

t_light				*light_new(t_light_type type, ...);

void				light_delete(t_light **me);

#endif
