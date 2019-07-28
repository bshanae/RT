#include "shape_moebius.h"

int			swap(double *a, double *b)
{
	double	tmp;

	tmp = *b;
	*b = *a;
	*a = tmp;
	return (1);
}

static t_moebius_equation	init_structure(const double *coefficient)
{
	t_moebius_equation		new;

	new.q = coefficient[2] * coefficient[2] - 3 * coefficient[1];
	new.r = 2 * coefficient[2] * coefficient[2] * coefficient[2] - 9 * coefficient[2] * coefficient[1] + 27 * coefficient[0];
	new.bq = new.q / 9;
	new.br = new.r / 54;
	new.bq3 = new.bq * new.bq * new.bq;
	new.br2 = new.br * new.br;
	new.cr2 = 729 * new.r * new.r;
	new.cq3 = 2916 * new.q * new.q * new.q;
	new.sgnbr = new.br >= 0 ? 1 : -1;
	new.i = 0;
	return (new);
}

static int					solve_second_case(t_moebius_equation c, const double *coefficient, double *r)
{
	c.sqrt_bq = sqrt(c.bq);
	if (c.br > 0)
	{
		r[0] = -2 * c.sqrt_bq - coefficient[2] / 3;
		r[1] = c.sqrt_bq - coefficient[2] / 3;
		r[2] = c.sqrt_bq - coefficient[2] / 3;
	}
	else
	{
		r[0] = -c.sqrt_bq - coefficient[2] / 3;
		r[1] = -c.sqrt_bq - coefficient[2] / 3;
		r[2] = 2 * c.sqrt_bq - coefficient[2] / 3;
	}
	return (3);
}

static int					solve_third_case(t_moebius_equation c, const double *coefficient, double *r)
{
	c.ratio = c.sgnbr * sqrt(c.br2 / c.bq3);
	c.theta = acos(c.ratio);
	c.norm = -2 * sqrt(c.bq);
	c.r0 = c.norm * cos(c.theta / 3) - coefficient[2] / 3;
	c.r1 = c.norm * cos((c.theta + 2.0 * M_PI) / 3) - coefficient[2] / 3;
	c.r2 = c.norm * cos((c.theta - 2.0 * M_PI) / 3) - coefficient[2] / 3;
	if (c.r0 > c.r1)
		swap(&c.r0, &c.r1);
	if (c.r1 > c.r2)
	{
		swap(&c.r1, &c.r2);
		if (c.r0 > c.r1)
			swap(&c.r0, &c.r1);
	}
	r[0] = c.r0;
	r[1] = c.r1;
	r[2] = c.r2;
	return (3);
}

static int					solve_fourth_case(t_moebius_equation c, const double *coefficient, double *r)
{
	c.ba = -c.sgnbr * pow(fabs(c.br) + sqrt(c.br2 - c.bq3), 1.0 / 3.0);
	c.bb = c.bq / c.ba;
	r[0] = c.ba + c.bb - coefficient[2] / 3;
	return (1);
}

int							solve_moebius_equation(double *coefficient, double *r)
{
	t_moebius_equation		c;

	c = init_structure(coefficient);
	if (c.br == 0 && c.bq == 0)
	{
		while (c.i++ < 3)
			r[c.i] = -coefficient[2] / 3;
		return (3);
	}
	else if (c.cr2 == c.cq3)
		return (solve_second_case(c, coefficient, r));
	else if (c.br2 < c.bq3)
		return (solve_third_case(c, coefficient, r));
	else
		return (solve_fourth_case(c, coefficient, r));
}

