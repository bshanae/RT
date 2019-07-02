#ifndef RP_COLOR_H
#define RP_COLOR_H

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

int                     color_unpack(t_vector3 vector);

#endif
