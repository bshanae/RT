#ifndef SHAPE_H
# define SHAPE_H

# include "parameters.h"

# include "material.h"
# include "intersection.h"

typedef	struct 						s_shape
{
	int 							id;
	unsigned char					data[SHAPE_DATA_SIZE_RESERVE];
	t_material						material;
	int								highlight;
}									t_shape;

#endif
