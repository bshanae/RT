#ifndef ASSERT_H
# define ASSERT_H

# include "libft_ft_printf.h"

# define ASSERT(statement)													\
	if (!(statement))														\
    {																		\
		ft_printf("{red}assertion failed : %d, %s\n", __LINE__, __func__);	\
		exit(2);															\
	}

#endif
