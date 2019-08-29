#ifndef RT_CONTROL_H
# define RT_CONTROL_H

//# define RT_NO_OPEN_CL
#define RT_IGNORE_SPECULAR

//# define RT_DEBUG
//# define RT_DEBUG_PIXEL_NUMBER 480 * 480
# define RT_DEBUG_CL_RT

# if !defined RT_FLOAT && !defined RT_DOUBLE
#  define RT_FLOAT
# endif

#endif
