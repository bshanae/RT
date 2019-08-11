#include "gui_signal_connect.h"

void				gui_signal_connect_scene_edit(t_gui *gui)
{
	GUI_CONNECT(gui->builder, gui_signal_scene_edit_select)
}

