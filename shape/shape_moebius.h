#ifndef MOEBIUS_H
# define MOEBIUS_H

# include "vector3.h"
# include "shape.h"

# define EPSILON 1e-9

typedef struct		s_moebius_equation
{
	double			q;
	double			r;
	double			bq;
	double			br;
	double			bq3;
	double			br2;
	double			cr2;
	double			cq3;
	double			sqrt_bq;
	double			sgnbr;
	double			ratio;
	double			theta;
	double			norm;
	double			r0;
	double			r1;
	double			r2;
	double			ba;
	double			bb;
	int				i;
}					t_moebius_equation;

typedef struct		s_moebius
{
	double 			radius;
	double 			ox;
	double 			dx;
	double 			oy;
	double 			dy;
	double 			oz;
	double 			dz;
	double 			max;
}					t_moebius;

typedef struct		s_shape_data_moebius
{
	double 			radius;
	double			half_width;
	t_vector3		position;
}					t_shape_data_moebius;

int					moebius_intersect(t_shape *shape, t_intersection *intersection);
int					solve_moebius_equation(double *coefficient, double *r);
t_shape				*shape_moebius(double radius, double max, t_vector3 position, t_material *material);

#endif
