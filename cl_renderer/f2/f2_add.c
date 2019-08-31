#include "f2.h"

RT_F2_API			f2_add(RT_F2_API a, RT_F2_API b)
{
	return ((RT_F2_API){a.x + b.x, a.y + b.y});
}
