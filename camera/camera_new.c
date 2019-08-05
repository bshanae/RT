#include "camera.h"

t_camera			*camera_new(void)
{
	t_camera		*new;

	new = (t_camera *)malloc(sizeof(t_camera));
	new->forward =
			(t_vector3){0., 0., -GI_DEFAULT_WIDTH / (tan((M_PI / 3.) / 2.))};
	new->axis_x = (t_vector3){1., 0., 0.};
	new->axis_y = (t_vector3){0., 1., 0.};
	new->axis_z = (t_vector3){0., 0., 1.};
	new->position = (t_vector3){0., 0., 0.};
	new->width = GI_DEFAULT_WIDTH;
	new->height = GI_DEFAULT_HEIGHT;
	return (new);
}
