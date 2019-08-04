#include "gui_image.h"

t_gui_image			*gui_image_new(void)
{
	t_gui_image		*new;

	new = malloc(sizeof(t_gui_image));
	new->image = NULL;
	return (new);
}