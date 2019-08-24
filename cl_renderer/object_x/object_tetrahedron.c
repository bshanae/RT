#include "object_interaction.h"

void						object_tetrahedron_build(t_object *space, va_list *args)
{
	t_object_tetrahedron	*data;

	data = (t_object_tetrahedron *)space->data;
	data->position = va_arg(*args, RT_F4_API);
	data->iterations = va_arg(*args, int);
	data->scale = (RT_F)va_arg(*args, double);
	space->type = object_tetrahedron;
}
