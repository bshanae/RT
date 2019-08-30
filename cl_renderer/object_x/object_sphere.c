#include "object_interaction.h"

void						object_sphere_build(t_object *space, va_list *args)
{
	t_object_sphere	*data;

	data = (t_object_sphere *)space->data;
	data->position = va_arg(*args, RT_F4_API);
	data->radius = (RT_F)va_arg(*args, double);
	space->texture_id = va_arg(*args, int);
	space->type = object_sphere;
}
