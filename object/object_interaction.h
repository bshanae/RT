#ifndef OBJECT_INTERACTION_H
# define OBJECT_INTERACTION_H

# include "object_definition.h"
# include "object_list.h"
# include "vector3.h"
# include "intersection.h"

# include <stdarg.h>

void				object_build(
					t_object *space,
					t_object_type type,
					...);

void				object_sphere_build(t_object *space, va_list *args);
void				object_plane_build(t_object *space, va_list *args);

int 				object_intersect
					(t_object *object, t_intersection *intersection);
int					object_sphere_intersect
					(t_object *object, t_intersection *intersection);
int					object_plane_intersect
					(t_object *object, t_intersection *intersection);

#endif
