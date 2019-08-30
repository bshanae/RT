#include "cl_renderer.h"

void 				cl_renderer_camera_request_focus
					(t_cl_renderer *renderer, int x, int y)
{
	cl_renderer_flag_set(renderer, cl_flag_update_camera);
	cl_renderer_flag_set(renderer, cl_flag_reset_samples);
	camera_request_focus(renderer->data.camera, x, y);
}