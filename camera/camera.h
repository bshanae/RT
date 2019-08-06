#ifndef CAMERA_H
# define CAMERA_H

# include "options.h"
# include "cl_include.h"

# include "libft_standart.h"
# include "ray.h"

# include <stdlib.h>
# include <math.h>

typedef struct 		s_camera
{
	cl_double4		position;
	cl_double4		axis_x;
	cl_double4		axis_y;
	cl_double4		axis_z;
	cl_double4		forward;
	int				width;
	int				height;
}					t_camera;

t_camera			*camera_new(INT_REF width, INT_REF height);
void 				camera_delete(t_camera **camera);

#endif
