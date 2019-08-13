#include "camera.h"

void 				camera_rotate
					(t_camera *camera,
					t_f4_rotation_axis axis,
					t_f4_rotation_direction direction,
					RT_F theta)
{
	RT_F4_API		*ptr;

	if (direction == rt_rotation_negative)
		theta *= -1;
	if (axis == rt_rotation_x)
		camera->rotation.x += theta;
	else if (axis == rt_rotation_y)
		camera->rotation.y += theta;
	camera->axis_x = (RT_F4_API){1., 0., 0.};
	camera->axis_y = (RT_F4_API){0., 1., 0.};
	camera->axis_z = (RT_F4_API){0., 0., 1.};
	camera->forward = camera->forward_backup;
	ptr = &camera->axis_x;
	while (ptr < &camera->forward_backup)
	{
		*ptr = f4_rotate(*ptr,
			rt_rotation_x, rt_rotation_positive, camera->rotation.x);
		*ptr = f4_rotate(*ptr,
			 rt_rotation_y, rt_rotation_positive, camera->rotation.y);
		ptr++;
	}
}