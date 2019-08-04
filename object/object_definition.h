#ifndef OBJECT_H
# define OBJECT_H

# include "options.h"

# include "object_type.h"

typedef struct		s_object
{
	t_object_type	type;
	char			data[OBJECT_DATA_CAPACITY];
}					t_object;



#endif
