#ifndef RT_CONTROL_H
# define RT_CONTROL_H

# define RT_NO_OPEN_CL

//# define RT_DEBUG
//# define RT_DEBUG_PIXEL_NUMBER 480 * 480
//# define RT_DEBUG_CL_RT

# define RT_CL_UNIFORM
//# define RT_DOUBLE

# if !defined RT_FLOAT && !defined RT_DOUBLE
#  define RT_FLOAT
# endif

# if !defined RT_CL_UNIFORM && !defined RT_CL_COSINE
#  define RT_CL_UNIFORM
# endif

#endif
