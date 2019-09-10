#include "gui_scene_edit.h"

void 							gui_scene_edit_init_own
								(t_gui_scene_edit *edit, GtkBuilder *builder)
{
	t_gui_init_control			init;

	edit->common = NULL;
	edit->stack = RT_GUI_GET(builder, "scene_edit_stack");
	edit->material_color_box =
		RT_GUI_GET(builder, "scene_edit_material_color_box");
	ft_strcpy(init.stack, "scene_edit_control");
	edit->control = gui_control_init(&init, builder);
	edit->info = RT_GUI_GET(builder, "scene_edit_info");
	edit->selection = RT_GUI_GET(builder, "scene_edit_selection");
	edit->remove_dialog = RT_GUI_GET(builder, "scene_edit_remove_dialog");
	edit->name = RT_GUI_GET(builder, "scene_edit_name");
	edit->type = RT_GUI_GET(builder, "scene_edit_type");
}
