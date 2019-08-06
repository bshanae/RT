#ifndef CL_INCLUDE_H
# define CL_INCLUDE_H

# include <OpenCL/opencl.h>

# ifdef __APPLE__
#  include <OpenCL/opencl.h>
# else
#  include <CL/cl.h>
# endif

#endif
