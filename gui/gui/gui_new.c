#include "gui.h"

t_gui				*gui_new(void)
{
	t_gui			*new;

	new = (t_gui *)malloc(sizeof(t_gui));
	new->builder = NULL;
	new->window = NULL;
	new->list = gui_list_new();
	new->object = gui_object_new();
	new->image = gui_image_new();
	return (new);
}