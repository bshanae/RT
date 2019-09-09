#include "object_interaction.h"

static void 		static_init(u_int *data)
{
	data[object_type_light_ambient] = RT_OBJECT_RT | RT_OBJECT_MOVE_A;
	data[object_type_light_point] = RT_OBJECT_RT | RT_OBJECT_MOVE_A;
	data[object_type_light_direct] = RT_OBJECT_RT | RT_OBJECT_MOVE_A;
	data[object_type_sphere] = RT_OBJECT_RT | RT_OBJECT_MOVE_A;
	data[object_type_plane] = RT_OBJECT_RT | RT_OBJECT_MOVE_A;
	data[object_type_cone] = RT_OBJECT_RT | RT_OBJECT_MOVE_B;
	data[object_type_cylinder] = RT_OBJECT_RT | RT_OBJECT_MOVE_B;
	data[object_type_box] = RT_OBJECT_RT | RT_OBJECT_MOVE_A;
	data[object_type_paraboloid] = RT_OBJECT_RT | RT_OBJECT_MOVE_A;
	data[object_type_moebius] = RT_OBJECT_RT | RT_OBJECT_MOVE_A;
	data[object_type_limited] = RT_OBJECT_RT | RT_OBJECT_MOVE_NONE;
	data[object_type_torus] = RT_OBJECT_RM | RT_OBJECT_MOVE_A;
	data[object_type_mandelbulb] = RT_OBJECT_RM | RT_OBJECT_MOVE_A;
	data[object_type_julia] = RT_OBJECT_RM | RT_OBJECT_MOVE_A;
	data[object_type_explosion] = RT_OBJECT_RM | RT_OBJECT_MOVE_A;
	data[object_type_perforated_cube] = RT_OBJECT_RM | RT_OBJECT_MOVE_A;
	data[object_type_csg] = RT_OBJECT_RM | RT_OBJECT_MOVE_NONE;
}

u_int 				object_flag_get(t_object *object)
{
	static u_int 	data[object_type_end];
	static int 		is_initialized;

	if (!is_initialized)
	{
		static_init(data);
		is_initialized = 1;
	}
	return (data[object->type]);
}
