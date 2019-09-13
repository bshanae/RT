#include "gui_signal_connect_x.h"

void				gui_signal_connect_scene_edit(t_gui *gui)
{
	printf("GUI Signal: Connecting object editor callbacks\n");
	RT_GUI_CONNECT(gui, gui_signal_scene_edit_select);
	RT_GUI_CONNECT(gui, gui_signal_scene_edit_entry_changed);
	RT_GUI_CONNECT(gui, gui_signal_scene_edit_entry_insert);
	RT_GUI_CONNECT(gui, gui_signal_scene_edit_entry_delete);
	RT_GUI_CONNECT(gui, gui_signal_scene_edit_combo_changed);
	RT_GUI_CONNECT(gui, gui_signal_scene_edit_reset);
	RT_GUI_CONNECT(gui, gui_signal_scene_edit_apply);
	RT_GUI_CONNECT(gui, gui_signal_scene_edit_material_color);
	RT_GUI_CONNECT(gui, gui_signal_scene_edit_material_emission);
	RT_GUI_CONNECT(gui, gui_signal_scene_edit_add);
	RT_GUI_CONNECT(gui, gui_signal_scene_edit_remove);
	RT_GUI_CONNECT(gui, gui_signal_scene_edit_remove_response_cancel);
	RT_GUI_CONNECT(gui, gui_signal_scene_edit_remove_response_yes);
	RT_GUI_CONNECT(gui, gui_signal_scene_edit_remove_response_no);
}

