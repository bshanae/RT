#include "error_framework.h"

void 				rt_assert(int statement, CHAR_REF message, ...)
{	va_list 		args;

	if (!statement)
	{
		va_start(args, message);
		rt_print_error(message, args);
		va_end(args);
	}
}

void 				rt_assert_critical(int statement, CHAR_REF message, ...)
{
	va_list 		args;

	if (!statement)
	{
		va_start(args, message);
		rt_print_error(message, args);
		va_end(args);
		exit(1);
	}
}