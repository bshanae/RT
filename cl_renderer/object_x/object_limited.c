#include "object_interaction.h"

void					object_limited_build(t_object *space, va_list *args)
{
	t_object_limited	*limited;

	limited = (t_object_limited *)space->data;
	limited->id_main = va_arg(*args, int);
	limited->id_limit = va_arg(*args, int);
	space->type = object_type_limited;
}