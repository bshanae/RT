#ifndef DISRUPTIONS_VECTOR2_H
#define DISRUPTIONS_VECTOR2_H

typedef struct		s_vector2
{
	double 			x;
	double 			y;
}					t_vector2;

double 				vector2_dot(const t_vector2 *a, const t_vector2 *b);

t_vector2			vector2_mul_components_cp(t_vector2 a, t_vector2 b);

t_vector2			vector2_mul(const t_vector2 *a, double value);

t_vector2			vector2_mul_cp(t_vector2 a, double value);

t_vector2			vector2_add_cp(t_vector2 a, t_vector2 b);

t_vector2			vector2_sub_cp(t_vector2 a, t_vector2 b);

double 				vector2_dot_cp(t_vector2 a, t_vector2 b);

#endif //DISRUPTIONS_VECTOR2_H
