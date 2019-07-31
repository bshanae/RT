#include <preferences.h>
#include <mach/mach_types.h>
#include "perlin_noise.h"

/*
 * 	Output: double from 0. to 1.
 */

t_vector2				hash(t_vector2 x)
{
	t_vector2 k = (t_vector2) {0.3183099, 0.3678794};

	x = vector2_mul_components_cp(x, k);
	x.x += k.y;
	x.y += k.x;
	k = vector2_mul(&k, 16. * FRACT(sin(x.x) * sin(x.y) * (x.x + x.y)));
	t_vector2 tmp = vector2_mul_cp((t_vector2){FRACT(k.x), FRACT(k.y)}, 2.);
	return ((t_vector2){tmp.x - 1., tmp.y - 1.});
}
#define INIGO

double 					compute_perlin_noise(double fx, double fy)
{
#ifdef INIGO
	t_vector2			integer_values = (t_vector2){floor(fx), floor(fy)};
	t_vector2			fractional_values = (t_vector2){fx - integer_values.x, fy - integer_values.y};
	t_vector2			u = vector2_mul_components_cp(fractional_values,fractional_values);

	double 				dot[4];
	double 				interpolation_result[3];

	// 00
	dot[0] = vector2_dot_cp(hash(vector2_add_cp(integer_values, (t_vector2){0., 0.})),
			vector2_sub_cp(fractional_values, (t_vector2){0., 0.}));
	// 10
	dot[1] = vector2_dot_cp(hash(vector2_add_cp(integer_values, (t_vector2){1., 0.})),
			vector2_sub_cp(fractional_values, (t_vector2){1., 0.}));
	// 01
	dot[2] = vector2_dot_cp(hash(vector2_add_cp(integer_values, (t_vector2){0., 1.})),
			vector2_sub_cp(fractional_values, (t_vector2){0., 1.}));
	// 11
	dot[3] = vector2_dot_cp(hash(vector2_add_cp(integer_values, (t_vector2){1., 1.})),
			vector2_sub_cp(fractional_values, (t_vector2){1., 1.}));

	// 00 10
	interpolation_result[0] = lerp(dot[0], dot[1], quantic_curve(u.x));
	// 01 11
	interpolation_result[1] = lerp(dot[2], dot[3], quantic_curve(u.x));
	// final interpolation
	interpolation_result[2] = lerp(interpolation_result[0], interpolation_result[1], quantic_curve(u.y));
	return (interpolation_result[2]);
#endif
#ifdef HABR
	int 				left;
	int 				top;
	double				point_in_x;
	double				point_in_y;
	double				dot_product[4];
	t_vector2			gradient[4];
	t_vector2			distance_to[4];

	/*
	 * 	Левая вершина квадрата
	 */

	left = (int)floor(fx);
	top = (int)floor(fy);

	/*
	 * 	Координаты точки внутри квадрата
	 */

	point_in_x = fx - left;
	point_in_y = fy - top;

	/*
	 * 	 Генерация градиентных векторов
	 * 	 для всех вершин квадрата
	 */

	gradient[0] = get_random_gradient_vector(left, top);
	gradient[1] = get_random_gradient_vector(left + 1, top);
	gradient[2] = get_random_gradient_vector(left, top + 1);
	gradient[3] = get_random_gradient_vector(left + 1, top + 1);


	/*
	 * 	Вектора от вершин до точки
	 * 	внутри квадрата
	 */

	distance_to[0] = (t_vector2){point_in_x, point_in_y};
	distance_to[1] = (t_vector2){point_in_x - 1, point_in_y};
	distance_to[2] = (t_vector2){point_in_x, point_in_y - 1};
	distance_to[3] = (t_vector2){point_in_x - 1, point_in_y - 1};

	/*
	 * 	Скалярные произведения для интерполяции
	 */

	dot_product[0] = vector2_dot(distance_to + 0, gradient + 0);
	dot_product[1] = vector2_dot(distance_to + 1, gradient + 1);
	dot_product[2] = vector2_dot(distance_to + 2, gradient + 2);
	dot_product[3] = vector2_dot(distance_to + 3, gradient + 3);

	/*
	 * 	Интерполяция
	 */

	point_in_x = quantic_curve(point_in_x);
	point_in_y = quantic_curve(point_in_y);

	double		tx = lerp(dot_product[0], dot_product[1], point_in_x);
	double		bx = lerp(dot_product[2], dot_product[3], point_in_x);
	double		tb = lerp(tx, bx, point_in_y);

	return (tb);
#endif
}

#define WOOD
double 					choose_perlin_noise(double x, double y)
{
	double 				amplitude = 1.;
	double 				result = 0.;
	double 				sum_amplitude = 0.;
#ifdef CLOUDS
	x *= 4.;
	y *= 4.;
	for (int i = 0; i < 15; i++)
	{
		result += amplitude * fabs(compute_perlin_noise(x, y));
		sum_amplitude += amplitude;
		x *= 2.;
		y *= 2.;
		amplitude *= .5;
	}
	return (result / sum_amplitude);
#endif
#ifdef WOOD
	for (int i = 0; i < 7; i++)
	{
		result += sqrt(x * x + y * y) + fabs(sin(compute_perlin_noise(x, y)));
		sum_amplitude += amplitude;
		x *= 1.7;
		y *= 1.7;
		amplitude *= .2;
	}
	return (result / sum_amplitude);
#endif
}

int						noise(double x, double y)
{
	double				perlin_result;
	t_vector2			uv;
	t_color				color;

	uv = (t_vector2){x / WINDOW_WIDTH, y / WINDOW_HEIGHT};
	uv.x *= (double)WINDOW_WIDTH / WINDOW_HEIGHT;
	perlin_result = choose_perlin_noise(uv.x, uv.y);
	perlin_result = 0.5 + 0.5 * perlin_result;
	CREATE_COLOR
	return (color.mix);
}