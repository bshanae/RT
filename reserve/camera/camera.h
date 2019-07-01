#ifndef CAMERA_H
# define CAMERA_H

# include "vector3.h"
# include "ray.h"

typedef struct			s_camera
{
	t_vector3			position;
	float				direction_length;
	t_vector3			direction;
	t_vector3			axis_x;
	t_vector3			axis_y;
	t_vector3			axis_z;
	t_vector3			vp_axis_x;
	t_vector3			vp_axis_y;
	t_vector3       	angles;
}						t_camera;

t_camera				camera_build(float direction_length);

void                	camera_recalculate(t_camera *me);

#endif
