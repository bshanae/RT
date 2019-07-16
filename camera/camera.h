#ifndef RP_CAMERA_H
# define RP_CAMERA_H

# include "options.h"

# include "libft_standart.h"
# include "vector3.h"
# include "ray.h"
# include "filter.h"

typedef struct 			s_camera
{
	t_vector3			position;
	t_vector3			forward;
	t_vector3			up;
	t_vector3			right;
}						t_camera;

t_camera				*camera_new();

void					camera_delete(t_camera **camera);

void					camera_focus(t_camera *camera, t_ray *ray);

t_ray					camera_build_ray(t_camera *camera, INT_REF x, INT_REF y);

#endif
