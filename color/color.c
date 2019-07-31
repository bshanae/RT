#include "color.h"

t_vector3			color_pack(int value)
{
	t_vector3		vector;
	t_color			color;

	color.mix = value;
	vector.x = color.rgb.r / 255.;
	vector.y = color.rgb.g / 255.;
	vector.z = color.rgb.b / 255.;
	return (vector);
}

#define RED_

int                 color_unpack_stereoscopy(t_vector3 vector, int i, int stereoscopy_mode)
{
	t_color         color;
	double 	*ptr;
	int 			counter;
	double 	left;

	ptr = &vector.x;
	counter = 0;
	left = 0.;
	while (counter++ < 3)
	{
		if (*ptr > 1.)
		{
			left += *ptr - 1.;
			*ptr = 1.;
		}
		ptr++;
	}
	if (i == 2 || !stereoscopy_mode)
	{
		if (i == 2 && stereoscopy_mode)
			color.rgb.a = 50;
		else
			color.rgb.a = 130;
		color.rgb.r = (unsigned char) (255. * vector.x);
		color.rgb.g = (unsigned char) (255. * vector.y);
		color.rgb.b = (unsigned char) (255. * vector.z);
	}
	else if (i == 0)
	{
		color.rgb.a = 150;
		color.rgb.r = 255;
		color.rgb.g = 0;
		color.rgb.b = 0;
	}
	else if (i == 1)
	{
		color.rgb.a = 150;
		color.rgb.r = 102;
		color.rgb.g = 255;
		color.rgb.b = 255;
	}
	return (color.mix);
}

int                 color_unpack(t_vector3 vector)
{
    t_color         color;
	double 	*ptr;
	int 			counter;
	double 	left;

	ptr = &vector.x;
	counter = 0;
	left = 0.;
	while (counter++ < 3)
	{
		if (*ptr > 1.)
		{
			left += *ptr - 1.;
			*ptr = 1.;
		}
		ptr++;
	}
#ifdef RED_FILTER
	color.rgb.a = 0;
    color.rgb.r = (unsigned char)(255. * vector.x);
    color.rgb.g = (unsigned char)(0. * vector.y);
    color.rgb.b = (unsigned char)(0. * vector.z);
#else
	color.rgb.a = 0;
	color.rgb.r = (unsigned char)(255. * vector.x);
	color.rgb.g = (unsigned char)(255. * vector.y);
	color.rgb.b = (unsigned char)(255. * vector.z);
#endif
    return (color.mix);
}