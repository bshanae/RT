#ifndef SHAPE_H
# define SHAPE_H

# include "parameters.h"

# include "libft_standart.h"
# include "intersection.h"

typedef struct		s_shape
{
	UCHAR			data[SHAPE_DATA_CAPACITY];
	int 			id;
	int 			material_id;
}					t_shape;

void				shape_intersect(t_shape *, t_intersection *)

#endif
