#include "object_definition.h"

const char 			*object_translate(t_object_type type)
{
	if (type == object_light_point)
		return ("point light");
	else if (type == object_light_direct)
		return ("direct light");
	else if (type == object_sphere)
		return ("sphere");
	else if (type == object_plane)
		return ("plane");
	else if (type == object_cone)
		return ("cone");
	else if (type == object_cylinder)
		return ("cylinder");
	return ("unknown");
}