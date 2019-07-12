#include "camera.h"

t_ray				camera_build_ray(t_camera *camera, INT_REF x, INT_REF y)
{
	t_ray			result;
	t_vector3		up;
	t_vector3		right;
	float 			xf;
	float 			yf;

	t_vector3		focal_point;

	xf = (float)*x;
	yf = (float)*y;
	filter_jitter_values(&xf, &yf);

	up = camera->up;
	right = camera->right;

	vector3_mul_eq(&right, xf - (WINDOW_WIDTH - 1.) / 2.);
	vector3_mul_eq(&up, -1. * yf + (WINDOW_HEIGHT - 1.) / 2.);
	result.direction = vector3_add_ref(&up, &right);
	vector3_add_eq_ref(&result.direction, &camera->forward);
	vector3_normalize(&result.direction);

	focal_point = vector3_add_cp(camera->position, vector3_mul_ref(&result.direction, FOCAL_LENGTH));

	result.origin = camera->position;

	result.origin.x += (.5 - drand48()) * APERTURE_SIZE;
	result.origin.y += (.5 - drand48()) * APERTURE_SIZE;
	result.origin.z += (.5 - drand48()) * APERTURE_SIZE;

	result.direction = vector3_sub_ref(&focal_point, &result.origin);
	vector3_normalize(&result.direction);

	return (result);
}