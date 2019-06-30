#include "light.h"

t_light				light_create(t_light_type type, ...)
{
	t_light			new;
	va_list 		args;

	new.type = type;
	va_start(args, type);
	new.intensity = (float)va_arg(args, double);
	if (type == light_point || type == light_directional)
		new.vector = va_arg(args, t_vector3);
	va_end(args);
	return (new);
}
