#include "object_interaction.h"

void				object_julia_build(t_object *space, va_list *args)
{
	t_object_julia	*data;

	data = (t_object_julia *)space->data;
	data->iterations = va_arg(*args, int);
	data->value = va_arg(*args, RT_F4_API);
	space->type = object_julia;
}
