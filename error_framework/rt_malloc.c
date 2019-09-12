#include "error_framework.h"

void				*rt_malloc(u_long size)
{
	void			*ptr;

	ptr = malloc(size);
	rt_assert_critical(ptr != NULL, "Allocation failed");
	return (ptr);
}