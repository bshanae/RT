#include "gui_signal_connect.h"

void 				gui_signal_connect_image(t_gui *gui)
{
	GUI_CONNECT(gui->builder, gui_signal_image_click);
}
