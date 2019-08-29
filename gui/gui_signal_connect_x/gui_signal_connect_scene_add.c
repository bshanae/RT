#include "gui_signal_connect_x.h"

void				gui_signal_connect_scene_add(t_gui *gui)
{
	printf("Connecting object creator signals\n");

	RT_GUI_CONNECT(gui, gui_signal_scene_add_response_cancel);
	RT_GUI_CONNECT(gui, gui_signal_scene_add_response_yes);
	RT_GUI_CONNECT(gui, gui_signal_scene_add_response_no);
	RT_GUI_CONNECT(gui, gui_signal_scene_add_type);
	RT_GUI_CONNECT(gui, gui_signal_scene_add_material_color);
	RT_GUI_CONNECT(gui, gui_signal_scene_add_material_emission);

}