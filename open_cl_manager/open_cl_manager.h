#ifndef OPEN_CL_MANAGER_H
# define OPEN_CL_MANAGER_H

# include <CL/cl.h>
# include <stdlib.h>

typedef struct		t_open_cl_manager
{

}					t_open_cl_manager;

t_open_cl_manager	*open_cl_manager_new(void);
void 				open_cl_manager_delete(t_open_cl_manager **open_cl);

#endif
