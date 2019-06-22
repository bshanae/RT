#ifndef SHAPE_H
# define SHAPE_H

# include "material.h"
# include "intersection.h"

typedef	struct 			s_shape
{
	void 				*data;
	unsigned long		data_size;
	int 				(*intersect)(struct s_shape *, t_intersection *);
	void				(*move)(struct s_shape *, t_vector3 move);
	const t_material	*material;
	int					highlight;
}						t_shape;

typedef	struct 			s_shape_cl
{
	int 				function_index;
	const t_material	material;
	int					highlight;
}						t_shape_cl;

void					shape_delete(t_shape **me);

#endif
