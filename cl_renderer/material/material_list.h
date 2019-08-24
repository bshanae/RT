#ifndef MATERIAL_LIST_H
# define MATERIAL_LIST_H

# include "color_list.h"

# define CAST_				(t_material)

# define MATERIAL_LIGHT		CAST_{COLOR_BLACK, LIGHT}

# define MATERIAL_WHITE		CAST_{COLOR_WHITE, COLOR_BLACK, 1., .5, 0., 0.}
# define MATERIAL_RED		CAST_{COLOR_RED, COLOR_BLACK, 1., .5, 0., 0.}
# define MATERIAL_GREEN		CAST_{COLOR_GREEN, COLOR_BLACK, 1., .5, 0., 0.}
# define MATERIAL_NONE		CAST_{COLOR_NONE, COLOR_NONE, 1., .5, 0., 0.}

#endif
