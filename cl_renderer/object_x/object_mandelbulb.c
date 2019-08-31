#include "object_interaction.h"

void						object_mandelbulb_build(t_object *space, va_list *args)
{
	t_object_mandelbulb		*data;

	data = (t_object_mandelbulb *)space->data;
	data->position = va_arg(*args, RT_F4_API);
	data->iterations = va_arg(*args, int);
	data->power = (RT_F)va_arg(*args, double);
	space->type = object_type_mandelbulb;
}
