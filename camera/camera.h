#ifndef CAMERA_H
# define CAMERA_H

# include "options.h"

# include "libft_standart.h"
# include "vector3.h"
# include "ray.h"

# include <stdlib.h>
# include <math.h>

typedef struct 		s_camera
{
	t_vector3		position;
	t_vector3		axis_x;
	t_vector3		axis_y;
	t_vector3		axis_z;
	t_vector3		forward;
	int				width;
	int				height;
}					t_camera;

t_camera			*camera_new(INT_REF width, INT_REF height);
void 				camera_delete(t_camera **camera);

t_ray				camera_build_ray(t_camera *camera, INT_REF x, INT_REF y);

#endif
