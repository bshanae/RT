#include "object_interaction.h"

void				object_build(
        t_object *space,
        t_object_type type,
        t_material material,
        ...)
{
    va_list		args;

    va_start(args, material);
    if (type == object_sphere)
        object_sphere_build(space, &args);
    else if (type == object_plane)
        object_plane_build(space, &args);
    else if (type == object_cone)
        object_cone_build(space, &args);
    else if (type == object_cylinder)
        object_cylinder_build(space, &args);
    else if (type == object_aabb)
        object_aabb_build(space, &args);
    space->material = material;
    space->name[0] = '\0';
    va_end(args);
}
