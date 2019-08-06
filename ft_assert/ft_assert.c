#include "ft_assert.h"

void				ft_assert(int statement, const char *message)
{
	if (statement)
		return ;
	ft_printf("{red}assertion failed : %s\n");
	exit(1);
}