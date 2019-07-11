#ifndef MATERIAL_LIST_H
# define MATERIAL_LIST_H

# include "color_list.h"

# define MATERIAL_LIGHT	(t_material){COLOR_WHITE, (t_vector3){3., 3., 3.}}

# define MATERIAL_WHITE	(t_material){COLOR_WHITE, COLOR_BLACK}
# define MATERIAL_GREY	(t_material){COLOR_GREY, COLOR_BLACK}
# define MATERIAL_RED	(t_material){COLOR_RED, COLOR_BLACK}
# define MATERIAL_GREEN	(t_material){COLOR_GREEN, COLOR_BLACK}

#endif
