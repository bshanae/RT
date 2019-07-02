#include "light.h"

t_light				*light_new(t_light_type type, ...)
{
	t_light			*new;
	va_list 		args;

	if (!(new = (t_light *)malloc(sizeof(t_light))))
		exit(21);
	new->type = type;
	va_start(args, type);
	new->intensity = (float)va_arg(args, double);
	if (type == light_point || type == light_directional)
		new->vector = va_arg(args, t_vector3);
	va_end(args);
	return (new);
}

void				light_delete(t_light **me)
{
	free(*me);
	*me = NULL;
}

