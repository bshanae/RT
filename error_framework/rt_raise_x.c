#include "error_framework.h"

void 				rt_raise_error(CHAR_REF message)
{
	printf("\n");
	printf("\033[0;31m");
	printf("RT_ERROR : %s\n", message);
	printf("\033[0m");
	printf("\n");
	exit(1);
}

void 				rt_raise_warning(CHAR_REF message)
{
	printf("\033[0;31m");
	printf("RT_WARNING : %s\n", message);
	printf("\033[0m");
}