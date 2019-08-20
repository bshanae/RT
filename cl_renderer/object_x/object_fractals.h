#ifndef OBJECT_FRACTALS_H
# define OBJECT_FRACTALS_H

typedef struct		s_object_fractal_settings
{
	int				iterations;
	RT_F			scale;
}					t_object_fractal_settings;

typedef struct		s_object_tetrahedron
{
	int				iterations;
	RT_F			scale;
}					t_object_tetrahedron;

typedef struct		s_object_mandelbulb
{
	int				iterations;
	RT_F			power;
	RT_F			bailout;
}					t_object_mandelbulb;

typedef struct		s_object_julia
{
	int				iterations;
	RT_F4_API		value;
}					t_object_julia;

#endif
