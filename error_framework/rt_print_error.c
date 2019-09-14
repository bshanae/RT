#include "error_framework.h"

void 				rt_print_error(CHAR_REF message, va_list args)
{
	printf("\033[0;31m");
	printf("RT_WARNING : ");
	vprintf(message, args);
	printf("\n");
	printf("\033[0m");
}
