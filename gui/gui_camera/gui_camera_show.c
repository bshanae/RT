#include "gui_camera.h"

void 				gui_camera_show(t_gui_camera *gui, const t_camera *camera)
{
	gui->control_silent = 1;
	gui_entry_set_f(gui->position_x, camera->position.x);
	gui_entry_set_f(gui->position_y, camera->position.y);
	gui_entry_set_f(gui->position_z, camera->position.z);
	gui_entry_set_f(gui->rotation_x, camera->rotation.x);
	gui_entry_set_f(gui->rotation_y, camera->rotation.y);
	gui_entry_set_f(gui->rotation_z, camera->rotation.z);
	gtk_switch_set_state(gui->antialiasing, camera->filter_antialiasing);
	RT_ASSERT((camera->filter_cartoon && camera->filter_sepia) != 1);
	gtk_toggle_button_set_active(gui->filter_none,
		!(camera->filter_cartoon && camera->filter_sepia));
	gtk_toggle_button_set_active(gui->filter_sepia, camera->filter_sepia);
	gtk_toggle_button_set_active(gui->filter_cartoon, camera->filter_cartoon);
	gtk_switch_set_state(gui->focus, camera->focus);
	gtk_widget_set_sensitive(GTK_WIDGET(gui->focus_box), camera->focus);
	gui_entry_set_f(gui->focus_focal_length, camera->focal_length);
	gui_entry_set_f(gui->focus_aperture_size, camera->aperture_size);
	gui->control_silent = 0;
}