#ifndef COLOR_H
# define COLOR_H

# include "math.h"
# include "vector3.h"

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

t_vector3				color_pack(int value);

int                     color_unpack(t_vector3 vector);

int                 	color_unpack_stereoscopy(t_vector3 vector, int i, int stereoscopy_mode);

#endif
