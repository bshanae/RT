#include "object_interaction.h"

void				object_plane_build(t_object *space, va_list *args)
{
	t_object_plane	*data;

	data = (t_object_plane *)space->data;
	data->position = va_arg(*args, RT_F4_API);
	data->normal = f4_normalize(va_arg(*args, RT_F4_API));
	data->is_limiting = va_arg(*args, int);
	space->type = object_type_plane;
}
