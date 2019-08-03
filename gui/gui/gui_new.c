#include "gui.h"

t_gui				*gui_new(void)
{
	t_gui			*new;

	new = (t_gui *)malloc(sizeof(t_gui));
	new->builder = NULL;
	new->window = NULL;
	new->scene = gui_scene_new();
	return (new);
}