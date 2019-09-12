#include "object_interaction.h"

void				object_csg_build(t_object *space, va_list *args)
{
	t_object_csg	*data;

	data = (t_object_csg *)space->data;
	data->positive_id = -1;
	data->negative_id = -1;
	ft_strcpy(data->positive_name, va_arg(*args, const char *));
	ft_strcpy(data->negative_name, va_arg(*args, const char *));
	space->type = object_type_csg;
}

