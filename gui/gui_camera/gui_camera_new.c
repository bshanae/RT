#include "gui_camera.h"

t_gui_camera		*gui_camera_new(GtkBuilder *builder)
{
	t_gui_camera	*new;

	new = malloc(sizeof(t_gui_camera));
	new->control = RT_GUI_GET(builder, "camera_control");
	new->control_silent = 0;
	gtk_widget_set_opacity(GTK_WIDGET(new->control), 0.);
	new->position_x = RT_GUI_GET(builder, "camera_position_x");
	new->position_y = RT_GUI_GET(builder, "camera_position_y");
	new->position_z = RT_GUI_GET(builder, "camera_position_z");
	new->rotation_x = RT_GUI_GET(builder, "camera_rotation_x");
	new->rotation_y = RT_GUI_GET(builder, "camera_rotation_y");
	new->rotation_z = RT_GUI_GET(builder, "camera_rotation_z");
	new->screen_success = RT_GUI_GET(builder, "camera_screen_dialog_success");
	new->screen_fail = RT_GUI_GET(builder, "camera_screen_dialog_fail");
	new->antialiasing = RT_GUI_GET(builder, "camera_filter_antialiasing");
	new->focus = RT_GUI_GET(builder, "camera_filter_focus");
	new->focus_box = RT_GUI_GET(builder, "camera_filter_focus_box");
	new->focal_length = RT_GUI_GET(builder, "camera_filter_focal_length");
	new->aperture_size = RT_GUI_GET(builder, "camera_filter_aperture_size");
	return (new);
}
