#include "cl_renderer.h"

void 				cl_renderer_camera_move
					(t_cl_renderer *renderer, t_camera_movement movement)
{
	camera_move(renderer->data.camera, movement, 1.f);
	// todo store step in cl_renderer
}

void 				cl_renderer_camera_rotate
					(t_cl_renderer *renderer,
					t_f4_rotation_axis axis,
					t_f4_rotation_direction direction)
{
	camera_rotate(renderer->data.camera, axis, direction, 0.025f);
	// todo store theta in cl_renderer
}