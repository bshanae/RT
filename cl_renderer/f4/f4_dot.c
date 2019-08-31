#include "f4.h"

RT_F				f4_dot(RT_F4_API a, RT_F4_API b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}