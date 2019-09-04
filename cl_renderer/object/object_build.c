#include "object_interaction.h"

void				object_build(
					t_object *space,
					t_object_type type,
					...)
{
	va_list		args;

	if (!space)
		return ;
	space->material = MATERIAL_WHITE;
	space->name[0] = '\0';
	space->texture_id = -1;
	space->is_visible = 1;
	space->is_selected = 0;
	space->is_limited = 0;
	va_start(args, type);
	if (type == object_type_light_ambient)
		object_light_ambient_build(space, &args);
	else if (type == object_type_light_point)
		object_light_point_build(space, &args);
	else if (type == object_type_light_direct)
		object_light_direct_build(space, &args);
	else if (type == object_type_sphere)
		object_sphere_build(space, &args);
	else if (type == object_type_plane)
		object_plane_build(space, &args);
	else if (type == object_type_cone)
		object_cone_build(space, &args);
	else if (type == object_type_cylinder)
		object_cylinder_build(space, &args);
	else if (type == object_type_box)
		object_box_build(space, &args);
	else if (type == object_type_paraboloid)
		object_paraboloid_build(space, &args);
	else if (type == object_type_moebius)
		object_moebius_build(space, &args);
	else if (type == object_type_limited)
		object_limited_build(space, &args);
	else if (type == object_type_torus)
		object_torus_build(space, &args);
	else if (type == object_type_mandelbulb)
		object_mandelbulb_build(space, &args);
	else if (type == object_type_julia)
		object_julia_build(space, &args);
	else if (type == object_type_explosion)
		object_explosion_build(space, &args);
	else if (type == object_type_perforated_cube)
		object_perforated_cube_build(space, &args);
	else if (type == object_type_csg)
		object_csg_build(space, &args);
	va_end(args);
}