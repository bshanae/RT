#ifndef OBJECT_INTERACTION_H
# define OBJECT_INTERACTION_H

# include "rt_assert.h"
# include "f4.h"
# include "object_definition.h"
# include "object_x.h"
# include "material_list.h"
# include "rt_float.h"

# include <stdarg.h>

t_object_flag		object_get_flag(t_object_type type);

void				object_build(t_object *space, t_object_type type, ...);

void				object_light_ambient_build(t_object *space, va_list *args);
void				object_light_point_build(t_object *space, va_list *args);
void				object_light_direct_build(t_object *space, va_list *args);
void				object_sphere_build(t_object *space, va_list *args);
void				object_plane_build(t_object *space, va_list *args);
void				object_cone_build(t_object *space, va_list *args);
void				object_cylinder_build(t_object *space, va_list *args);
void                object_box_build(t_object *space, va_list *args);
void				object_paraboloid_build(t_object *space, va_list *args);
void                object_moebius_build(t_object *space, va_list *args);
void				object_limited_build(t_object *space, va_list *args);
void                object_torus_build(t_object *space, va_list *args);
void                object_mandelbulb_build(t_object *space, va_list *args);
void                object_julia_build(t_object *space, va_list *args);
void				object_perforated_cube_build(t_object *space, va_list *args);
void				object_explosion_build(t_object *space, va_list *args);
void				object_csg_build(t_object *space, va_list *args);

#endif
