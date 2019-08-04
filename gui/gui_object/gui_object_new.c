#include "gui/gui_object/gui_object.h"

t_gui_object		*gui_object_new(void)
{
	t_gui_object	*new;

	new = malloc(sizeof(t_gui_object));
	new->current_widget = NULL;
	new->current_id = -1;
	new->overlay = NULL;
	return (new);
}
