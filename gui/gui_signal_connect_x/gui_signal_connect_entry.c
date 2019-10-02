#include "gui_signal_connect_x.h"

void 				gui_signal_connect_entry(t_gui *gui)
{
	printf("GUI Signal: Connecting entry callbacks\n");
	RT_GUI_CONNECT(gui, gui_signal_entry_launch_control_on_insert);
	RT_GUI_CONNECT(gui, gui_signal_entry_launch_control_on_delete);
	RT_GUI_CONNECT(gui, gui_signal_entry_block_i);
	RT_GUI_CONNECT(gui, gui_signal_entry_block_f);
}