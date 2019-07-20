#ifndef SHAPE_H
# define SHAPE_H

# include "options.h"

# include "libft_standart.h"

# include "material.h"
# include "intersection.h"

typedef struct		s_shape
{
	UCHAR			data[SHAPE_DATA_CAPACITY];
	int 			id;
	t_material		material;
}					t_shape;

int					shape_intersect(t_shape *, t_intersection *);

#endif
