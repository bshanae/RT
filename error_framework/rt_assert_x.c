#include "error_framework.h"

void 				rt_assert(int statement, CHAR_REF message, ...)
{	va_list 		args;

	va_start(args, message);
	if (!statement)
		rt_raise_warning(message, args);
	va_end(args);

}

void 				rt_assert_critical(int statement, CHAR_REF message, ...)
{
	va_list 		args;

	va_start(args, message);

	if (!statement)
		rt_raise_error(message, args);
	va_end(args);
}