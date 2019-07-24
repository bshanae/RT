#include "camera.h"

t_camera			*camera_new()
{
	t_camera		*new;

	new = (t_camera *)malloc_guard(sizeof(t_camera));
	new->forward = (t_vector3){0., 0., -WINDOW_WIDTH / (tan((M_PI / 3.) / 2.))};
	new->right = (t_vector3){1., 0., 0.};
	new->up = (t_vector3){0., 1., 0.};
	new->position = (t_vector3){0., 0., 0.};
	return (new);
}