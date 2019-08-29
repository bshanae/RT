#include "object_interaction.h"

static int 			is_object_csg_valid(t_object *space, t_object_csg *data)
{
	return (data->id_positive < space->id && data->id_negative < space->id && space->id > 1);
}

void				object_csg_build(t_object *space, va_list *args)
{
	t_object_csg	*data;

	data = (t_object_csg *)space->data;
	data->id_positive = va_arg(*args, int);
	data->id_negative = va_arg(*args, int);
	if (!is_object_csg_valid(space, data))
	{
		data->id_positive = 0;
		data->id_negative = 0;
	}
	space->type = object_csg;
}

// todo: improve (add object_invalid)