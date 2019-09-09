#include "camera.h"

RT_F4_API			camera_move
					(t_camera *camera,
					 t_movement movement,
					 RT_F length)
{
	RT_F4_API		step;

	step = camera_get_step(camera, movement);
	step = f4_mul(step, length);
	return (f4_add(camera->position, step));
}