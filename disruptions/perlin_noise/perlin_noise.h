#ifndef DISRUPTIONS_PERLIN_NOISE_H
#define DISRUPTIONS_PERLIN_NOISE_H

# include "vector2/vector2.h"

# include "math.h"

# define FRACT(x) x - floor(x)
# define CREATE_COLOR \
			color.rgb.a = 255; \
			color.rgb.r = (char)(255 * perlin_result); \
			color.rgb.g = (char)(255 * perlin_result); \
			color.rgb.b = (char)(255 * perlin_result); \

typedef struct			s_rgb
{
	unsigned char		b;
	unsigned char		g;
	unsigned char		r;
	unsigned char		a;
}						t_rgb;

typedef union			u_color
{
	int					mix;
	t_rgb				rgb;
}						t_color;

double					lerp(double a, double b, double t);

double					quantic_curve(double t);

t_vector2				get_random_gradient_vector(unsigned int x, unsigned int y);

int						noise(double x, double y);

double 					compute_perlin_noise(double fx, double fy);

#endif
