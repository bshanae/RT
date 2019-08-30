#include "cl_renderer.h"

int 				cl_renderer_camera_move
					(t_cl_renderer *renderer, t_camera_movement movement)
{
	RT_F4_API		test;

	test = camera_move(renderer->data.camera, movement, 1.f);
	if (scene_point_check(renderer->data.scene, &test) == SCENE_POINT_INSIDE)
		renderer->data.camera->position = test;
	else
		return (0);
	return (1);
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