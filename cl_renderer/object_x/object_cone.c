#include "object_interaction.h"

void				object_cone_build(t_object *space, va_list *args)
{
	t_object_cone	*data;
	RT_F4_API		axis_not_normal;

	data = (t_object_cone *)space->data;
	data->top = va_arg(*args, RT_F4_API);
	data->bottom = va_arg(*args, RT_F4_API);
	data->radius = (RT_F)va_arg(*args, double);
	axis_not_normal = f4_sub(data->bottom, data->top);
	data->axis = f4_normalize(axis_not_normal);
	data->tangent = data->radius / f4_length(axis_not_normal);
	space->type = object_cone;
}
