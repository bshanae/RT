#include "camera.h"

void				camera_apply(t_camera *camera)
{
	RT_F4_API		*ptr;

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
		*ptr = f4_rotate(*ptr,
			rt_rotation_z, rt_rotation_positive, camera->rotation.z);
		ptr++;
	}
}
