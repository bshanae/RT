#ifndef RT_CL_INCLUDE_H
# define RT_CL_INCLUDE_H

# ifdef __APPLE__
#  include <OpenCL/opencl.h>
# else
#  include <CL/cl.h>
# endif

# define CL_SILENCE_DEPRECATION
# pragma OPENCL EXTENSION cl_khr_fp64 : enable

#endif
