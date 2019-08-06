#include "camera.h"

t_camera			*camera_new(INT_REF width, INT_REF height)
{
	t_camera		*new;

	new = (t_camera *)malloc(sizeof(t_camera));
	new->forward =
			(API_FLOAT4){0., 0., - *width / (tan((M_PI / 3.) / 2.))};
	new->axis_x = (API_FLOAT4){1., 0., 0.};
	new->axis_y = (API_FLOAT4){0., 1., 0.};
	new->axis_z = (API_FLOAT4){0., 0., 1.};
	new->position = (API_FLOAT4){0., 0., 0.};
	new->width = *width;
	new->height = *height;
	return (new);
}
