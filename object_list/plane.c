#include "object_build.h"
#include "object_data.h"

void				object_plane_build(t_object *space, va_list *args)
{
	t_object_plane	*data;

	data = (t_object_plane *)space->data;
	data->position = va_arg(*args, t_vector3);
	data->normal = va_arg(*args, t_vector3);
	space->type = object_plane;
}