#include "object_interaction.h"

void				object_build(
					t_object *space,
					t_object_type type,
					t_material material,
					int visiable,
					...)
{
	va_list		args;

	va_start(args, visiable);
	if (type == object_sphere)
		object_sphere_build(space, &args);
	else if (type == object_plane)
		object_plane_build(space, &args);
	else if (type == object_cone)
		object_cone_build(space, &args);
	else if (type == object_cylinder)
		object_cylinder_build(space, &args);
	else if (type == object_paraboloid)
		object_paraboloid_build(space, &args);
    else if (type == object_moebius)
        object_moebius_build(space, &args);
	else if (type == object_julia)
		object_julia_build(space, &args);
	else if (type == object_tetrahedron)
		object_tetrahedron_build(space, &args);
	else if (type == object_mandelbulb)
		object_mandelbulb_build(space, &args);
	else if (type == object_torus)
		object_torus_build(space, &args);
	else if (type == object_box)
		object_box_build(space, &args);
	else if (type == object_csg)
		object_csg_build(space, &args);
	space->material = material;
	space->name[0] = '\0';
	space->visiable = visiable;
	va_end(args);
}
