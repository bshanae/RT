#include "camera.h"

t_vector3			camera_build_ray(t_camera *camera, INT_REF x, INT_REF y)
{
	t_vector3		ray;
	t_vector3		up;
	t_vector3		right;
	float 			xf;
	float 			yf;

	xf = (float)*x;
	yf = (float)*y;
	filter_jitter_values(&xf, &yf);

	up = camera->up;
	right = camera->right;

	vector3_mul_eq(&up, -1. * yf + (WINDOW_HEIGHT - 1.) / 2.);
	vector3_mul_eq(&right, xf - (WINDOW_WIDTH - 1.) / 2.);
	ray = vector3_add_ref(&up, &right);
	vector3_add_eq_ref(&ray, &camera->forward);
	vector3_normalize(&ray);
	//todo jittering
	//todo focus
	return (ray);
}