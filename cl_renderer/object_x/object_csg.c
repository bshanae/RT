#include "object_interaction.h"

void				object_csg_build(t_object *space, va_list *args)
{
	t_object_csg	*data;

	data = (t_object_csg *)space->data;
	data->id_positive = va_arg(*args, int);
	data->id_negative = va_arg(*args, int);
	space->type = object_csg;
}
