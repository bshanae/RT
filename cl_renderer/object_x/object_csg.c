#include "object_interaction.h"

void				object_csg_build(t_object *space, va_list *args)
{
	t_object_csg	*data;

	data = (t_object_csg *)space->data;
	data->id_subtrahend = va_arg(*args, int);
	data->id_subtractor = va_arg(*args, int);
	data->mod = va_arg(*args, t_csg_mod);
	space->type = object_csg;
}
