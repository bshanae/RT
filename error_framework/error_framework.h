#ifndef RT_ERROR_FRAMEWORK_H
# define RT_ERROR_FRAMEWORK_H

# include "libft_standart.h"

# include <stdio.h>

void 				rt_raise_error(CHAR_REF message);
void 				rt_raise_warning(CHAR_REF message);

void 				rt_assert(int statement, CHAR_REF message);
void 				rt_assert_critical(int statement, CHAR_REF message);

#endif
