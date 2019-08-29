#include "gui_signal_connect_x.h"

void 				gui_signal_connect_image(t_gui *gui)
{
	printf("Connecting image signals\n");
	RT_GUI_CONNECT(gui, gui_signal_image_click);
}
