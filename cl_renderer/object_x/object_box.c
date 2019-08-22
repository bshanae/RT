#include "object_interaction.h"

void				object_box_build(t_object *space, va_list *args)
{
	t_object_box	*data;

	data = (t_object_box *)space->data;
	data->position = va_arg(*args, RT_F4_API);
	data->size = va_arg(*args, RT_F4_API);
	space->type = object_box;
}
