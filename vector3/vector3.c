#include "vector3.h"

t_vector3			*vector3_new(int num_of_elements, ...)
{
	t_vector3		*new;
	va_list 		args;

	if (!(new = (t_vector3 *)malloc(sizeof(t_vector3))))
		exit(21);
	va_start(args, num_of_elements);
	if (num_of_elements == 1)
	{
		new->x = (double)va_arg(args, double);
		new->y = new->x;
		new->z = new->x;
	}
	else if (num_of_elements == 3)
	{
		new->x = (double)va_arg(args, double);
		new->y = (double)va_arg(args, double);
		new->z = (double)va_arg(args, double);
	}
	else
	{
		va_end(args);
		free(new);
		return (NULL);
	}
	va_end(args);
	return (new);
}

void				vector3_delete(t_vector3 **me)
{
	free(*me);
	*me = NULL;
}

double 		vector3_length(const t_vector3 *me)
{
	return (sqrtf(me->x * me->x + me->y * me->y + me->z * me->z));
}

double 		vector3_s_length(const t_vector3 me)
{
	return (sqrtf(me.x * me.x + me.y * me.y + me.z * me.z));
}

void				vector3_normalize(t_vector3 *me)
{
	double		length;

	length = vector3_length(me);
	me->x /= length;
	me->y /= length;
	me->z /= length;
}

t_vector3			vector3_s_normalize(t_vector3 me)
{
	double		length;

	length = vector3_length(&me);
	me.x /= length;
	me.y /= length;
	me.z /= length;
	return (me);
}

t_vector3			vector3_normalized(const t_vector3 *me)
{
	t_vector3		result;

	result = *me;
	vector3_normalize(&result);
	return (result);
}

double 		vector3_dot(const t_vector3 *v1, const t_vector3 *v2)
{
	return (v1->x * v2->x + v1->y * v2->y + v1->z * v2->z);
}

double 		vector3_s_dot(t_vector3 v1, t_vector3 v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}


t_vector3			vector3_cross(const t_vector3 *v1, const t_vector3 *v2)
{
	t_vector3		result;

	result.x = v1->y * v2->z - v1->z * v2->y;
	result.y = v1->z * v2->x - v1->x * v2->z;
	result.z = v1->x * v2->y - v1->y * v2->x;
	return (result);
}

t_vector3			vector3_s_cross(t_vector3 v1, t_vector3 v2)
{
	t_vector3		result;

	result.x = v1.y * v2.z - v1.z * v2.y;
	result.y = v1.z * v2.x - v1.x * v2.z;
	result.z = v1.x * v2.y - v1.y * v2.x;
	return (result);
}

t_vector3			vector3_sub(t_vector3 *v1, t_vector3 *v2)
{
	t_vector3		result;

	result.x = v1->x - v2->x;
	result.y = v1->y - v2->y;
	result.z = v1->z - v2->z;
	return (result);
}

t_vector3			vector3_s_sub(t_vector3 v1, t_vector3 v2)
{
	t_vector3		result;

	result.x = v1.x - v2.x;
	result.y = v1.y - v2.y;
	result.z = v1.z - v2.z;
	return (result);
}

void				vector3_sub_eq(t_vector3 *v1, const t_vector3 *v2)
{
	v1->x -= v2->x;
	v1->y -= v2->y;
	v1->z -= v2->z;
}

void				vector3_s_sub_eq(t_vector3 *v1, t_vector3 v2)
{
	v1->x -= v2.x;
	v1->y -= v2.y;
	v1->z -= v2.z;
}


t_vector3			vector3_add(const t_vector3 *v1, const t_vector3 *v2)
{
	t_vector3		result;

	result.x = v1->x + v2->x;
	result.y = v1->y + v2->y;
	result.z = v1->z + v2->z;
	return (result);
}

t_vector3			vector3_s_add(t_vector3 v1, t_vector3 v2)
{
	v1.x += v2.x;
	v1.y += v2.y;
	v1.z += v2.z;
	return (v1);
}

void				vector3_add_eq(t_vector3 *v1, const t_vector3 *v2)
{
	v1->x += v2->x;
	v1->y += v2->y;
	v1->z += v2->z;
}

void				vector3_s_add_eq(t_vector3 *v1, t_vector3 v2)
{
	v1->x += v2.x;
	v1->y += v2.y;
	v1->z += v2.z;
}

t_vector3			vector3_mul(const t_vector3 *v1, double k)
{
	t_vector3		result;

	result.x = v1->x * k;
	result.y = v1->y * k;
	result.z = v1->z * k;
	return (result);
}

t_vector3			vector3_s_mul(t_vector3 v1, double k)
{
	v1.x *= k;
	v1.y *= k;
	v1.z *= k;
	return (v1);
}

void				vector3_mul_eq(t_vector3 *v1, double k)
{
	v1->x = v1->x * k;
	v1->y = v1->y * k;
	v1->z = v1->z * k;
}

t_vector3			vector3_div(const t_vector3 *v1, double k)
{
	t_vector3		result;

	result.x = v1->x / k;
	result.y = v1->y / k;
	result.z = v1->z / k;
	return (result);
}

t_vector3			vector3_s_div(t_vector3 v1, double k)
{
	t_vector3		result;

	result.x = v1.x / k;
	result.y = v1.y / k;
	result.z = v1.z / k;
	return (result);
}

void				vector3_div_eq(t_vector3 *v1, double k)
{
	v1->x = v1->x / k;
	v1->y = v1->y / k;
	v1->z = v1->z / k;
}

double			*vector3_iter(t_vector3 *me, int i)
{
	if (i < 0 || i > 3)
		return (NULL);
	return (&me->x + i);
}

void				vector3_rotate_x(t_vector3 *me, double theta)
{
	t_vector3		copy;

	copy = *me;
	me->y = copy.y * cosf(theta) + copy.z * sinf(theta);
	me->z = -1 * copy.y * sinf(theta) + copy.z * cosf(theta);
}

void				vector3_rotate_y(t_vector3 *me, double theta)
{
	t_vector3		copy;

	copy = *me;
	me->x = copy.x * cosf(theta) + copy.z * sinf(theta);
	me->z = -1 * copy.x * sinf(theta) + copy.z * cosf(theta);
}