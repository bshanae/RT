#ifndef VECTOR3_H
# define VECTOR3_H

# include "math.h"

typedef struct 			s_vector3
{
	float 				x;
	float 				y;
	float 				z;
}						t_vector3;

# define VECTOR3_REF	const t_vector3 *

t_vector3				vector3_mul_ref(VECTOR3_REF, float);
t_vector3				vector3_mul_cp(t_vector3, float);
void					vector3_mul_eq(t_vector3 *, float);

t_vector3				vector3_add_ref(VECTOR3_REF, VECTOR3_REF);
t_vector3				vector3_add_cp(t_vector3, t_vector3);
void					vector3_add_eq_ref(t_vector3 *, VECTOR3_REF);
void					vector3_add_eq_cp(t_vector3 *, t_vector3);


#endif
