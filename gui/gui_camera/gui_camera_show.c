#include "gui_camera.h"

void 				gui_camera_show(t_gui_camera *gui, const t_camera *camera)
{
	gui_entry_set_f(gui->position_x, camera->position.x);
	gui_entry_set_f(gui->position_y, camera->position.y);
	gui_entry_set_f(gui->position_z, camera->position.z);
	gui_entry_set_f(gui->rotation_x, camera->rotation.x);
	gui_entry_set_f(gui->rotation_y, camera->rotation.y);
	gui_entry_set_f(gui->rotation_z, camera->rotation.z);
	gtk_switch_set_state(gui->antialiasing, camera->antialiasing);
	gtk_switch_set_state(gui->focus, camera->focus);
	gui_entry_set_f(gui->focal_length, camera->focal_length);
	gui_entry_set_f(gui->aperture_size, camera->aperture_size);
}