#ifndef OBJECT_BUILD_H
# define OBJECT_BUILD_H

# include "vector3.h"
# include "object_definition.h"
# include "object_data.h"

# include <stdarg.h>

void				object_build(
					t_object *space,
					t_object_type type,
					...);

void				object_sphere_build(t_object *space, va_list *args);
void				object_plane_build(t_object *space, va_list *args);

#endif
