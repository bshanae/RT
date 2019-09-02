#ifndef COLOR_LIST_H
# define COLOR_LIST_H

# include "rt_cl_include.h"
# include "rt_float.h"

# define LIGHT					(RT_F4_API){1., 1., 1., 1.}
# define LIGHT_BASIC			(RT_F4_API){0.3, 0.3, 0.3, 1.}
# define LIGHT_AMBIENT			(RT_F4_API){0.5, 0.5, 0.5, 1.}

# define COLOR_WHITE			(RT_F4_API){1., 1., 1., 1.}
# define COLOR_BLACK			(RT_F4_API){0., 0., 0., 1.}
# define COLOR_RED				(RT_F4_API){1., 0., 0., 1.}
# define COLOR_GREEN			(RT_F4_API){0., 1., 0., 1.}
# define COLOR_BLUE				(RT_F4_API){0., 0., 1., 1.}

# define COLOR_NONE				(RT_F4_API){-1., -1., -1., -1.}
# define COLOR_EXPLOSION		(RT_F4_API){0.1, 0., 0., 0.}

#endif
