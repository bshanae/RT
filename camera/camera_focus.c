#include "camera.h"

void				camera_focus(t_camera *camera, t_ray *ray)
{
	t_vector3		focal_point;

	focal_point = vector3_add_cp(camera->position, vector3_mul_ref(&ray->direction, FOCAL_LENGTH));

	ray->origin.x += (.5 - drand48()) * APERTURE_SIZE;
	ray->origin.y += (.5 - drand48()) * APERTURE_SIZE;
	ray->origin.z += (.5 - drand48()) * APERTURE_SIZE;

	ray->direction = vector3_sub_ref(&focal_point, &ray->origin);
	vector3_normalize(&ray->direction);
}