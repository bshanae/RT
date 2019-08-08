#include "cl_renderer.h"

void 				cl_renderer_camera_move
					(t_cl_renderer *renderer, t_camera_direction direction)
{
	renderer->flags.update_camera = 1;
	camera_move(renderer->data_host.camera, direction, 1.);
}