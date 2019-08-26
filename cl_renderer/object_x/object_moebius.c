#include "object_interaction.h"

void				    object_moebius_build(t_object *space, va_list *args)
{
    t_object_moebius	*data;

    data = (t_object_moebius *)space->data;
    data->position = va_arg(*args, RT_F4_API);
    data->radius = (RT_F)va_arg(*args, double);
    data->half_width = 2 * (RT_F)va_arg(*args, double);
    space->type = object_moebius;
}
