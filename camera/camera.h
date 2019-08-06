#ifndef CAMERA_H
# define CAMERA_H

# include "options.h"
# include "cl_parameters/cl_float.h"

# include "libft_standart.h"
# include "ray.h"

# include <stdlib.h>
# include <math.h>

typedef struct 		s_camera
{
	API_FLOAT4		position;
	API_FLOAT4		axis_x;
	API_FLOAT4		axis_y;
	API_FLOAT4		axis_z;
	API_FLOAT4		forward;
	int				width;
	int				height;
}					t_camera;

t_camera			*camera_new(INT_REF width, INT_REF height);
void 				camera_delete(t_camera **camera);

#endif
