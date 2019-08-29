#include "object_interaction.h"

void							object_perforated_cube_build(t_object *space, va_list *args)
{
	t_object_perforated_cube	*data;

	data = (t_object_perforated_cube *)space->data;
	data->position = va_arg(*args, RT_F4_API);
	data->iterations = va_arg(*args, int);
	space->type = object_perforated_cube;
}
