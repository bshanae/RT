#include "gui_camera.h"

t_gui_camera		*gui_camera_new(GtkBuilder *builder)
{
	t_gui_camera	*new;

	new = malloc(sizeof(t_gui_camera));
	return (new);
}
