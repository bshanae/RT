#include "object_interaction.h"

void				object_aabb_build(t_object *space, va_list *args)
{
    t_object_aabb	*data;

    data = (t_object_aabb *)space->data;
    data->min = va_arg(*args, RT_F4_API);
    data->max = va_arg(*args, RT_F4_API);
    space->type = object_aabb;
}

