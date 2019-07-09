#ifndef RP_CAMERA_H
# define RP_CAMERA_H

# include "parameters.h"

# include "vector3.h"
# include "libft_standart.h"

typedef struct 		s_camera
{
	t_vector3		position;
	t_vector3		forward;
	t_vector3		up;
	t_vector3		right;

}					t_camera;

t_camera			*camera_new();

void				camera_delete(t_camera **camera);

t_vector3			camera_build_ray(t_camera *camera, INT_REF x, INT_REF y);

#endif
