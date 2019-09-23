#include "gui_camera.h"

t_gui_camera			*gui_camera_new(GtkBuilder *builder)
{
	t_gui_camera		*new;
	t_gui_init_control	init;

	printf("GUI : Initializing camera\n");
	new = rt_malloc(sizeof(t_gui_camera));
	new->connected = rt_false;
	new->ptr_camera = NULL;
	new->ptr_light = NULL;
	ft_strcpy(init.stack, "camera_control");
	new->control = gui_control_init(&init, builder);
	new->position_x = RT_GUI_GET(builder, "camera_position_x");
	new->position_y = RT_GUI_GET(builder, "camera_position_y");
	new->position_z = RT_GUI_GET(builder, "camera_position_z");
	new->rotation_x = RT_GUI_GET(builder, "camera_rotation_x");
	new->rotation_y = RT_GUI_GET(builder, "camera_rotation_y");
	new->rotation_z = RT_GUI_GET(builder, "camera_rotation_z");
	new->state_dialog = RT_GUI_GET(builder, "camera_state_dialog");
	new->state_label = RT_GUI_GET(builder, "camera_state_label");
	new->screen_dialog = RT_GUI_GET(builder, "camera_screen_dialog");
	new->screen_label = RT_GUI_GET(builder, "camera_screen_label");
	new->antialiasing = RT_GUI_GET(builder, "camera_antialiasing");
	new->filter_none = RT_GUI_GET(builder, "camera_filter_none");
	new->filter_cartoon_box = RT_GUI_GET(builder, "camera_filter_cartoon_box");
	new->filter_cartoon = RT_GUI_GET(builder, "camera_filter_cartoon");
	new->filter_sepia = RT_GUI_GET(builder, "camera_filter_sepia");
	new->filter_stereo = RT_GUI_GET(builder, "camera_filter_stereo");
	new->focus = RT_GUI_GET(builder, "camera_focus");
	new->focus_request = 0;
	new->focus_box = RT_GUI_GET(builder, "camera_focus_box");
	new->focus_focal_length = RT_GUI_GET(builder, "camera_focus_focal_length");
	new->focus_aperture_size =
		RT_GUI_GET(builder, "camera_focus_aperture_size");
	return (new);
}
