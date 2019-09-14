#include "object_interaction.h"

static void 		static_init_a(u_int *data)
{
	data[object_type_light_ambient] = RT_OBJECT_RT | RT_OBJECT_RM;
	data[object_type_light_point] = RT_OBJECT_RT | RT_OBJECT_RM;
	data[object_type_light_direct] = RT_OBJECT_RT | RT_OBJECT_RM;
	data[object_type_sphere] = RT_OBJECT_RT | RT_OBJECT_RM;
	data[object_type_plane] = RT_OBJECT_RT | RT_OBJECT_RM;
	data[object_type_cone] = RT_OBJECT_RT;
	data[object_type_cylinder] = RT_OBJECT_RT;
	data[object_type_box] = RT_OBJECT_RT | RT_OBJECT_RM;
	data[object_type_paraboloid] = RT_OBJECT_RT;
	data[object_type_moebius] = RT_OBJECT_RT;
	data[object_type_limited] = RT_OBJECT_RT;
	data[object_type_torus] = RT_OBJECT_RM;
	data[object_type_mandelbulb] = RT_OBJECT_RM;
	data[object_type_julia] = RT_OBJECT_RM;
	data[object_type_explosion] = RT_OBJECT_RM;
	data[object_type_perforated_cube] = RT_OBJECT_RM;
	data[object_type_csg] = RT_OBJECT_RM;
}

static void 		static_init_b(u_int *data)
{
	data[object_type_light_ambient] |= RT_OBJECT_MOVE_A;
	data[object_type_light_point] |= RT_OBJECT_MOVE_A;
	data[object_type_light_direct] |= RT_OBJECT_MOVE_A;
	data[object_type_sphere] |= RT_OBJECT_MOVE_A;
	data[object_type_plane] |= RT_OBJECT_MOVE_A;
	data[object_type_cone] |= RT_OBJECT_MOVE_B;
	data[object_type_cylinder] |= RT_OBJECT_MOVE_B;
	data[object_type_box] |= RT_OBJECT_MOVE_A;
	data[object_type_paraboloid] |= RT_OBJECT_MOVE_A;
	data[object_type_moebius] |= RT_OBJECT_MOVE_A;
	data[object_type_limited] |= RT_OBJECT_MOVE_NONE;
	data[object_type_torus] |= RT_OBJECT_MOVE_A;
	data[object_type_mandelbulb] |= RT_OBJECT_MOVE_A;
	data[object_type_julia] |= RT_OBJECT_MOVE_A;
	data[object_type_explosion] |= RT_OBJECT_MOVE_A;
	data[object_type_perforated_cube] |= RT_OBJECT_MOVE_A;
	data[object_type_csg] |= RT_OBJECT_MOVE_NONE;
}


static void 		static_init_c(u_int *data)
{
	data[object_type_light_ambient] |= RT_OBJECT_LIGHT;
	data[object_type_light_point] |= RT_OBJECT_LIGHT;
	data[object_type_light_direct] |= RT_OBJECT_LIGHT;
	data[object_type_sphere] |= RT_OBJECT_LIMITABLE;
	data[object_type_plane] |= RT_OBJECT_LIMITING;
	data[object_type_sphere] |= RT_OBJECT_CSG;
	data[object_type_plane] |= RT_OBJECT_CSG;
	data[object_type_limited] |= RT_OBJECT_PAIR;
	data[object_type_torus] |= RT_OBJECT_CSG;
	data[object_type_csg] |= RT_OBJECT_PAIR;
}


u_int 				object_flag_get(t_object *object)
{
	static u_int 	data[object_type_end];
	static int 		is_initialized;

	if (!is_initialized)
	{
		static_init_a(data);
		static_init_b(data);
		static_init_c(data);
		is_initialized = 1;
	}
	return (data[object->type]);
}
