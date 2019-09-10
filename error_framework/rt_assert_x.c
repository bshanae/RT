#include "error_framework.h"

void 				rt_assert(int statement, CHAR_REF message)
{
	if (!statement)
		rt_raise_warning(message);
}

void 				rt_assert_critical(int statement, CHAR_REF message)
{
	if (!statement)
		rt_raise_error(message);
}