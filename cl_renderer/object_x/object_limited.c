#include "object_interaction.h"

void					object_limited_build(t_object *space, va_list *args)
{
	t_object_limited	*limited;

	limited = (t_object_limited *)space->data;
	limited->main_id = -1;
	limited->limit_id = -1;
	ft_strcpy(limited->main_name, va_arg(*args, const char *));
	ft_strcpy(limited->limit_name, va_arg(*args, const char *));
	space->type = object_type_limited;
}