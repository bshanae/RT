#include "object_interaction.h"

void				    object_paraboloid_build(t_object *space, va_list *args)
{
	t_object_paraboloid	*data;

	data = (t_object_paraboloid *)space->data;
	data->extremum = va_arg(*args, RT_F4_API);
	data->axis = f4_normalize(va_arg(*args, RT_F4_API));
	data->radius = (RT_F)va_arg(*args, double);
	space->type = object_type_paraboloid;
}
