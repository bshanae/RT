#include "f4.h"

RT_F4_API			f4_normalize(RT_F4_API source)
{
    RT_F			length;

    length = f4_length(source);
    return ((RT_F4_API){
            source.x / length,
            source.y / length,
            source.z / length,
            source.w
    });
}
