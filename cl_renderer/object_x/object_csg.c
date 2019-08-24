#include "object_interaction.h"

void				object_csg_build(t_object *space, va_list *args)
{
	t_object_csg	*data;

	data = (t_object_csg *)space->data;
	data->object_0 = va_arg(*args, t_object);
	data->object_1 = va_arg(*args, t_object);
	data->mod = va_arg(*args, t_csg_mod);
	space->type = object_csg;
}
