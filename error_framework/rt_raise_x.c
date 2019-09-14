#include "error_framework.h"


void 				rt_raise_error(CHAR_REF message, ...)
{
	va_list 		args;

	va_start(args, message);
	rt_print_error(message, args);
	va_end(args);
	exit(1);
}

void 				rt_raise_warning(CHAR_REF message, ...)
{
	va_list 		args;

	va_start(args, message);
	rt_print_error(message, args);
	va_end(args);
}