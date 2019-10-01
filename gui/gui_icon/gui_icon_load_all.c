#include "gui_icon.h"

void 				gui_icon_load_all(GtkBuilder *builder)
{
	t_pair_i		size;

	printf("GUI : Loading icons\n");
	size = (t_pair_i){18, 18};
	gui_icon_load(builder, "icon_parser", RT_SOURCE_GUI_ICON_PARSER, size);
	size = (t_pair_i){20, 20};
	gui_icon_load(builder, "icon_camera", RT_SOURCE_GUI_ICON_CAMERA, size);
	size = (t_pair_i){25, 25};
	gui_icon_load(builder, "icon_scene", RT_SOURCE_GUI_ICON_SCENE, size);
	size = (t_pair_i){22, 22};
	gui_icon_load(builder, "icon_settings", RT_SOURCE_GUI_ICON_SETTINGS, size);
	size = (t_pair_i){14, 14};
	gui_icon_load(builder, "icon_plus", RT_SOURCE_GUI_ICON_PLUS, size);
	gui_icon_load(builder, "icon_minus", RT_SOURCE_GUI_ICON_MINUS, size);
	gui_icon_load(builder, "icon_add_no", RT_SOURCE_GUI_ICON_ADD_NO, size);
	gui_icon_load(builder, "icon_add_yes", RT_SOURCE_GUI_ICON_ADD_YES, size);
}
