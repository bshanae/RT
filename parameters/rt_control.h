#ifndef RT_CONTROL_H
# define RT_CONTROL_H

//# define RT_OPEN_CL_DISABLED
# define RT_OPEN_CL_CPU
# define RT_OPEN_CL_LOW

# if !defined RT_FLOAT && !defined RT_DOUBLE
#  define RT_FLOAT
# endif

# if !defined RT_OPEN_CL_CPU && !defined RT_OPEN_CL_GPU
#  define RT_OPEN_CL_GPU
# endif

#endif
