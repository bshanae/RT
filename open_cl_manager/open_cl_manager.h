#ifndef OPEN_CL_MANAGER_H
# define OPEN_CL_MANAGER_H

# include "ft_assert.h"

# ifdef __APPLE__
#  include <OpenCL/opencl.h>
# else
#  include <CL/cl.h>
# endif
# include <stdlib.h>

# define CL_SILENCE_DEPRECATION
# define OCL_BUFF_INIT 1000
# define OCL_BUFF_MULT 5

typedef struct			t_open_cl_manager
{
	cl_device_id 		device_id;
	cl_context 			context;
}						t_open_cl_manager;

t_open_cl_manager		*open_cl_manager_new(void);
void 					open_cl_manager_delete(t_open_cl_manager **open_cl);

void					open_cl_manager_init_device(t_open_cl_manager *open_cl);
void					open_cl_manager_init_context(t_open_cl_manager *open_cl);

#endif
