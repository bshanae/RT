#include "camera.h"

void				camera_request_focus(t_camera *camera, int x, int y)
{
	camera->focus_request = 1;
	camera->focus_request_value.x = x;
	camera->focus_request_value.y = y;
}