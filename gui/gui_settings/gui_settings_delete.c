#include "gui_settings.h"

void 				gui_settings_delete(t_gui_settings **settings)
{
	free(*settings);
	*settings = NULL;
}