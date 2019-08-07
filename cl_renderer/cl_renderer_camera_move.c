#include "cl_renderer.h"

void 				cl_renderer_camera_move
					(t_cl_renderer *renderer, t_cl_direction direction)
{
	renderer->flags.update_camera = 1;
	// todo call camera move
}