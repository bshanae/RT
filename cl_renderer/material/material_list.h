#ifndef MATERIAL_LIST_H
# define MATERIAL_LIST_H

# include "color_list.h"

# define MATERIAL_LIGHT		(t_material){COLOR_BLACK, LIGHT}

# define MATERIAL_WHITE		(t_material){COLOR_WHITE, COLOR_BLACK, 0., 0.}
# define MATERIAL_RED		(t_material){COLOR_RED, COLOR_BLACK, 0., 0.}
# define MATERIAL_GREEN		(t_material){COLOR_GREEN, COLOR_BLACK, 0., 0.}

# define MATERIAL_MIRROR	(t_material){COLOR_WHITE, COLOR_BLACK, 1., 0.}
# define MATERIAL_GLASS		(t_material){COLOR_WHITE, COLOR_BLACK, 0., 1.}

#endif
