#ifndef RT_CONTROL_H
# define RT_CONTROL_H

//# define RT_OPEN_CL_DISABLED
# define RT_OPEN_CL_GPU
# define RT_OPEN_CL_ILLUMINATION_DISABLED
# define RT_OPEN_CL_AUTOFOCUS_DISABLED
# define RT_OPEN_CL_RT_ONLY
# define RT_OPEN_CL_LIGHT_BASIC_DISABLED

#  define RT_SAMPLE_MANUAL

# if !defined RT_OPEN_CL_CPU && !defined RT_OPEN_CL_GPU
#  define RT_OPEN_CL_GPU
# endif

# if !defined RT_SAMPLE_AUTO && !defined RT_SAMPLE_MANUAL
#  define RT_SAMPLE_AUTO
# endif

# if !defined RT_FLOAT && !defined RT_DOUBLE
#  define RT_FLOAT
# endif


#endif
