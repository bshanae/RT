#include "color.h"

void				color_correct(t_vector3 *color)
{
	// SRGB correction

	color->x = pow(color->x, 0.45);
	color->y = pow(color->y, 0.45);
	color->z = pow(color->z, 0.45);
}