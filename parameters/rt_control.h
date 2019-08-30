#ifndef RT_CONTROL_H
# define RT_CONTROL_H

//# define RT_OPEN_CL_DISABLED
# define RT_OPEN_CL_GPU
# define RT_OPEN_CL_ILLUMINATION_DISABLED
# define RT_OPEN_CL_AUTOFOCUS_DISABLED
# define RT_OPEN_CL_RT_ONLY
# define RT_OPEN_CL_LIGHT_BASIC_DISABLED

# if !defined RT_OPEN_CL_CPU && !defined RT_OPEN_CL_GPU
#  define RT_OPEN_CL_CPU
# endif

# if !defined RT_FLOAT && !defined RT_DOUBLE
#  define RT_FLOAT
# endif

#endif
