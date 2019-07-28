#include "camera.h"

t_camera			*camera_new(double direction_length)
{
	t_camera		*new;

	if (!(new = (t_camera *)malloc(sizeof(t_camera))))
		exit(21);
	new->position = (t_vector3){0., 0., 0.};
	*(double *)&new->direction_length = direction_length;
	new->direction = (t_vector3){0., 0., -direction_length};
	new->axis_x = (t_vector3){1., 0., 0.};
	new->axis_y = (t_vector3){0., 1., 0.};
	new->axis_z = (t_vector3){0., 0., 1.};
	new->vp_axis_x =  (t_vector3){1., 0., 0.};
	new->vp_axis_y = (t_vector3){0., 1., 0.};
	new->angles = (t_vector3){0., 0., 0.};
	return (new);
}

void			camera_delete(t_camera **me)
{
	free(*me);
	*me = NULL;
}

void			camera_build_cl(t_camera *me, t_camera_cl *cl)
{
	cl->direction = me->direction;
	cl->position = me->position;
	cl->vp_axis_x = me->vp_axis_x;
	cl->vp_axis_y = me->vp_axis_y;
}

t_ray			camera_cast_ray(t_camera *me, t_vector3 *vp_values)
{
	t_ray		tmp;
	t_vector3   up;
	t_vector3   right;
	t_vector3	point;

	right = me->vp_axis_x;
	up = me->vp_axis_y;
	vector3_mul_eq(&right, vp_values->x);
	vector3_mul_eq(&up, vp_values->y);
	point = vector3_add(&right, &up);
	tmp.origin = me->position;
	tmp.direction = vector3_add(&me->direction, &point);
	vector3_normalize(&tmp.direction);
	return (tmp);
}

void            camera_recalculate(t_camera *me)
{
	int         index;
	t_vector3   *iter;

	me->direction = (t_vector3){0., 0., -1 * me->direction_length};
	me->axis_x = (t_vector3){1., 0., 0.};
	me->axis_y = (t_vector3){0., 1., 0.};
	me->axis_z = (t_vector3){0., 0., 1.};
	me->vp_axis_x =  (t_vector3){1., 0., 0.};
	me->vp_axis_y = (t_vector3){0., 1., 0.};
	index = 0;
	iter = &me->direction;
	while (index < 6)
	{
		vector3_rotate_x(iter + index, me->angles.x);
		vector3_rotate_y(iter + index, me->angles.y);
		index++;
	}
}
