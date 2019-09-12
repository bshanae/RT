#include "camera.h"

t_camera			*camera_new(INT_REF width, INT_REF height)
{
	t_camera		*new;

	new = (t_camera *)rt_malloc(sizeof(t_camera));
	new->position = (RT_F4_API){0., 0., 0.};
	new->rotation = (RT_F4_API){0., 0., 0.};
	new->forward =
		(RT_F4_API){0., 0., -1. *  *width / (tan((M_PI / 3.) / 2.))};
	new->forward_backup = new->forward;
	new->axis_x = (RT_F4_API){1., 0., 0.};
	new->axis_y = (RT_F4_API){0., 1., 0.};
	new->axis_z = (RT_F4_API){0., 0., 1.};
	new->width = *width;
	new->height = *height;
	new->filter_antialiasing = RT_CL_ANTIALIASING;
    new->filter_cartoon = RT_CL_CARTOON_EFFECT;
    new->filter_sepia = RT_CL_FILTER_SEPIA;
	new->filter_stereo = RT_CL_FILTER_STEREO;
	new->focus = RT_CL_FOCUS;
	new->aperture_size = RT_CL_APERTURE_SIZE;
	new->focal_length = RT_CL_FOCAL_LENGTH;
	new->focus_request = 0;
	new->select_request = 0;
	new->select_request_object = -1;
	return (new);
}
