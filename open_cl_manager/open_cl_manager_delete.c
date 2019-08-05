#include "open_cl_manager.h"

void 				open_cl_manager_delete(t_open_cl_manager **open_cl)
{
	free(*open_cl);
	*open_cl = NULL;
}