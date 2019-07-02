#ifndef CAMERA_H
# define CAMERA_H

# include "parameters.h"

# include "ray.h"

# define CAMERA_UP		(t_vector3){0., 1., 0}
# define CAMERA_RIGHT	(t_vector3){1., 0., 0}

typedef struct			s_camera
{
	t_vector3			position;
	t_vector3			direction;
}						t_camera;

t_camera				*camera_new(void);

void					camera_delete(t_camera **me);

t_ray					camera_cast_ray(t_camera *me, t_vector3 *vp_values);

#endif
