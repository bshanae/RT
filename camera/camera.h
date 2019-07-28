#ifndef CAMERA_H
# define CAMERA_H

# include "vector3.h"
# include "ray.h"

typedef struct			s_camera
{
	t_vector3			position;
	const double	direction_length;
	t_vector3			direction;
	t_vector3			axis_x;
	t_vector3			axis_y;
	t_vector3			axis_z;
	t_vector3			vp_axis_x;
	t_vector3			vp_axis_y;
	t_vector3       	angles;
}						t_camera;

typedef struct			s_camera_cl
{
	t_vector3			position;
	t_vector3			direction;
	t_vector3			vp_axis_x;
	t_vector3			vp_axis_y;
}						t_camera_cl;

t_camera				*camera_new(double direction_length);

void					camera_delete(t_camera **me);

void					camera_build_cl(t_camera *me, t_camera_cl *cl);

t_ray					camera_cast_ray(t_camera *me, t_vector3 *vp_values);

void                	camera_recalculate(t_camera *me);

#endif
