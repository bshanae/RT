#include "camera.h"

t_ray				camera_build_ray(t_camera *camera, INT_REF x, INT_REF y)
{
	t_ray			result;
	t_vector3		up;
	t_vector3		right;
	float 			xf;
	float 			yf;

	xf = (float)*x;
	yf = (float)*y;
	if (PIXEL_JITTERING)
		filter_jitter_values(&xf, &yf);
	result.origin = camera->position;
	up = camera->up;
	right = camera->right;
	vector3_mul_eq(&right, xf - (WINDOW_WIDTH - 1.) / 2.);
	vector3_mul_eq(&up, -1. * yf + (WINDOW_HEIGHT - 1.) / 2.);
	result.direction = vector3_add_ref(&up, &right);
	vector3_add_eq_ref(&result.direction, &camera->forward);
	vector3_normalize(&result.direction);
	if (FOCUS_EFFECT)
		camera_focus(camera, &result);
	return (result);
}