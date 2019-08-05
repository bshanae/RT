#include "object_build.h"

void				object_build(
					t_object *space,
					t_object_type type,
					...)
{
	va_list		args;

	va_start(args, type);
	if (type == object_sphere)
		object_sphere_build(space, &args);
	else if (type == object_plane)
		object_plane_build(space, &args);
	va_end(args);
}