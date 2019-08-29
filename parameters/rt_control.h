#ifndef RT_CONTROL_H
# define RT_CONTROL_H

//# define RT_OPEN_CL_DISABLED
# define RT_OPEN_CL_LOW
# define RT_OPEN_CL_CPU

# if !defined RT_FLOAT && !defined RT_DOUBLE
#  define RT_FLOAT
# endif

#endif
