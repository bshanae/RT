#ifndef RT_CONTROL_H
# define RT_CONTROL_H

# define RT_OPEN_CL_GPU

# if !defined RT_FLOAT && !defined RT_DOUBLE
#  define RT_FLOAT
# endif

# if !defined RT_OPEN_CL_CPU && !defined RT_OPEN_CL_GPU
#  define RT_OPEN_CL_GPU
# endif

# if !defined RT_QUEUE_MANUAL && !defined RT_QUEUE_AUTO
#  define RT_QUEUE_AUTO
# endif

#endif
