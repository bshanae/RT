#include "camera.h"

t_camera			*camera_new(void)
{
	t_camera		*new;

	if (!(new = (t_camera *)malloc(sizeof(t_camera))))
		exit(21);
	new->position = (t_vector3){0., 0., 0.};
	new->direction = (t_vector3){0., 0., -WINDOW_WIDTH / (tan((M_PI / 3.) / 2.))};
	return (new);
}

void			camera_delete(t_camera **me)
{
	free(*me);
	*me = NULL;
}

t_ray			camera_cast_ray(t_camera *me, t_vector3 *vp_values)
{
	t_ray		tmp;
	t_vector3   up;
	t_vector3   right;
	t_vector3	point;

	right = CAMERA_RIGHT;
	up = CAMERA_UP;
	vector3_mul_eq(&right, vp_values->x);
	vector3_mul_eq(&up, vp_values->y);
	point = vector3_add(&right, &up);
	tmp.origin = me->position;
	tmp.direction = vector3_add(&me->direction, &point);
	vector3_normalize(&tmp.direction);
	return (tmp);
}