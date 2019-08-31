#ifndef CAMERA_H
# define CAMERA_H

# include "rt_parameters.h"
# include "rt_float.h"

# include "libft_standart.h"
# include "f4.h"
# include "ray.h"

# include <stdlib.h>
# include <math.h>

typedef struct 		s_camera
{
	RT_F4_API		position;
	RT_F4_API		rotation;
	RT_F4_API		axis_x;
	RT_F4_API		axis_y;
	RT_F4_API		axis_z;
	RT_F4_API		forward;
	RT_F4_API		forward_backup;
	int				width;
	int				height;
	int 			filter_antialiasing;
	int             filter_cartoon;
	int             filter_sepia;
	int 			focus;
	RT_F			aperture_size;
	RT_F			focal_length;
	int 			focus_request;
	int 			select_request;
	int 			select_request_object;
	RT_F2_API		request_value;
}					t_camera;

t_camera			*camera_new(INT_REF width, INT_REF height);
void 				camera_delete(t_camera **camera);

typedef enum		e_camera_movement
{
	rt_movement_left,
	rt_movement_right,
	rt_movement_up,
	rt_movement_down,
	rt_movement_forward,
	rt_movement_backward
}					t_camera_movement;

RT_F4_API			camera_move
					(t_camera *camera,
					 t_camera_movement direction,
					 RT_F length);
void 				camera_rotate
					(t_camera *camera,
					t_f4_rotation_axis axis,
					t_f4_rotation_direction direction,
					RT_F theta);
void				camera_apply(t_camera *camera);

void				camera_request_focus(t_camera *camera, int x, int y);
void				camera_request_select(t_camera *camera, int x, int y);

#endif
