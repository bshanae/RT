#include "f4.h"

RT_F4_API			f4_cross(RT_F4_API a, RT_F4_API b)
{
	return ((RT_F4_API){
			a.y * b.z - a.z * b.y,
			a.z * b.x - a.x * b.z,
			a.x * b.y - a.y * b.x,
			a.w - b.w
	});
}
