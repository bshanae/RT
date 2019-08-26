#include "gui_camera.h"

void 				gui_camera_delete(t_gui_camera **camera)
{
	free(*camera);
	*camera = NULL;
}