#include "object_interaction.h"

void						object_light_ambient_build
							(t_object *space, va_list *args)
{
	t_object_light_ambient	*data;

	data = (t_object_light_ambient *)space->data;
	space->type = object_light_ambient;
}

void						object_light_point_build
							(t_object *space, va_list *args)
{
	t_object_light_point	*data;

	data = (t_object_light_point *)space->data;
	data->position = va_arg(*args, RT_F4_API);
	space->type = object_light_point;
}


void						object_light_direct_build
							(t_object *space, va_list *args)
{
	t_object_light_direct	*data;

	data = (t_object_light_direct *)space->data;
	data->direction = f4_normalize(va_arg(*args, RT_F4_API));
	space->type = object_light_direct;
}