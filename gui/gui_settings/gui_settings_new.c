#include "gui_settings.h"

t_gui_settings		*gui_settings_new(GtkBuilder *builder)
{
	t_gui_settings	*new;

	new = malloc(sizeof(t_gui_settings));
	return (new);
}