#include "gui_list.h"

t_gui_list		*gui_list_new(void)
{
	t_gui_list	*new;

	new = malloc(sizeof(t_gui_list));
	new->data = NULL;
	new->view = NULL;
	new->select = NULL;
	return (new);
}