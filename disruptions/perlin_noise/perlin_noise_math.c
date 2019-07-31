#include <stdlib.h>
#include "perlin_noise.h"

/*
 * 	Linear interpolation
 */

double					lerp(double a, double b, double t)
{
	return (a + t * (b - a));
}

/*
 * 	Other interpolation variants
 * 	usage: lerp(a, b, quantic_curve(t))
 */

double					quantic_curve(double t)
{
	return (t * t * t * (t * (t * 6 - 15) + 10));
}
