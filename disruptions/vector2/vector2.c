#include "vector2.h"

double 				vector2_dot(const t_vector2 *a, const t_vector2 *b)
{
	return (a->x * b->x + a->y * b->y);
}

double 				vector2_dot_cp(t_vector2 a, t_vector2 b)
{
	return (a.x * b.x + a.y * b.y);
}

t_vector2			vector2_mul_components_cp(t_vector2 a, t_vector2 b)
{
	return ((t_vector2){a.x * b.x, a.y * b.y});
}

t_vector2			vector2_mul(const t_vector2 *a, double value)
{
	return ((t_vector2){a->x * value, a->y * value});
}

t_vector2			vector2_mul_cp(t_vector2 a, double value)
{
	return ((t_vector2){a.x * value, a.y * value});
}

t_vector2			vector2_add_cp(t_vector2 a, t_vector2 b)
{
	return ((t_vector2){a.x + b.x, a.y + b.y});
}

t_vector2			vector2_sub_cp(t_vector2 a, t_vector2 b)
{
	return ((t_vector2){a.x - b.x, a.y - b.y});
}