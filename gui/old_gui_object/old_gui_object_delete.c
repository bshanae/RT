#include "old_gui_object.h"

void				gui_object_delete(old_t_gui_object **object)
{
	free(*object);
	*object = NULL;
}