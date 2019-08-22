#include "object_interaction.h"

void						object_torus_build(t_object *space, va_list *args)
{
	t_object_torus			*data;

	data = (t_object_torus *)space->data;
	data->position = va_arg(*args, RT_F4_API);
	data->t_0 = (RT_F)va_arg(*args, double);
	data->t_1 = (RT_F)va_arg(*args, double);
	space->type = object_torus;
}
