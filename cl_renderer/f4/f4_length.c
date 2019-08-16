#include "f4.h"

RT_F				f4_length(RT_F4_API f4)
{
	return (RT_SQRT_API(f4.x * f4.x + f4.y * f4.y + f4.z * f4.z));
}