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
}