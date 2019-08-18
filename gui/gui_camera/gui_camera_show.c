#include "gui_camera.h"

void 				gui_camera_show(t_gui_camera *gui, const t_camera *camera)
{
	char 			buffer[32];

	ft_bzero(buffer, 32);
	sprintf(buffer, "%.2f", camera->position.x);
	gtk_entry_set_text(gui->position_x, buffer);
	sprintf(buffer, "%.2f", camera->position.y);
	gtk_entry_set_text(gui->position_y, buffer);
	sprintf(buffer, "%.2f", camera->position.z);
	gtk_entry_set_text(gui->position_z, buffer);
	sprintf(buffer, "%.2f", camera->rotation.x);
	gtk_entry_set_text(gui->rotation_x, buffer);
	sprintf(buffer, "%.2f", camera->rotation.y);
	gtk_entry_set_text(gui->rotation_y, buffer);
	sprintf(buffer, "%.2f", camera->rotation.z);
	gtk_entry_set_text(gui->rotation_z, buffer);
	gtk_switch_set_state(gui->antialiasing, camera->antialiasing);
	gtk_switch_set_state(gui->focus, camera->focus);
	sprintf(buffer, "%.2f", camera->focal_length);
	gtk_entry_set_text(gui->focal_length, buffer);
	sprintf(buffer, "%.2f", camera->aperture_size);
	gtk_entry_set_text(gui->aperture_size, buffer);
}