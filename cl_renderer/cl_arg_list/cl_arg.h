#ifndef CL_ARG_H
# define CL_ARG_H

# include "rt_cl_include.h"

typedef struct 		s_cl_arg
{
	void 			*host;
	cl_mem			device;
	u_long 			size;
	int 			update_need;
}					t_cl_arg;

#endif
