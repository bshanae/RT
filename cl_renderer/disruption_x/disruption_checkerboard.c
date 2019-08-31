#include "disruption.h"

RT_F4_API 			disruption_checkerboard(double x, double y)
{
	double 			value;

	value = floor(x * 1.931) + floor(y * 1.931);
	if (fmod(value, 2.) == 0)
		return (COLOR_WHITE);
	return (COLOR_BLACK);
}
