#include "gui_camera.h"

t_gui_camera		*gui_camera_new(GtkBuilder *builder)
{
	t_gui_camera	*new;

	new = malloc(sizeof(t_gui_camera));
	new->position_x = GTK_ENTRY(RT_GUI_GET(builder, "camera_position_x"));
	new->position_y = GTK_ENTRY(RT_GUI_GET(builder, "camera_position_y"));
	new->position_z = GTK_ENTRY(RT_GUI_GET(builder, "camera_position_z"));
	new->direction_x = GTK_ENTRY(RT_GUI_GET(builder, "camera_direction_x"));
	new->direction_y = GTK_ENTRY(RT_GUI_GET(builder, "camera_direction_y"));
	new->direction_z = GTK_ENTRY(RT_GUI_GET(builder, "camera_direction_z"));
	return (new);
}
