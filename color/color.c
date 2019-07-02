#include "color.h"

int                 color_unpack(t_vector3 vector)
{
	t_color         color;
	float 	*ptr;
	int 			counter;
	float 	left;

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
	color.rgb.a = 0;
	color.rgb.r = (unsigned char)(255. * vector.x);
	color.rgb.g = (unsigned char)(255. * vector.y);
	color.rgb.b = (unsigned char)(255. * vector.z);
	return (color.mix);
}
