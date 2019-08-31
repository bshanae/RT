#include "object_interaction.h"

static void					static_data_init(t_object_flag *data)
{
	data[object_type_light_ambient] = object_flag_universal;
	data[object_type_light_point] = object_flag_universal;
	data[object_type_light_direct] = object_flag_universal;
	data[object_type_sphere] = object_flag_universal;
	data[object_type_plane] = object_flag_universal;
	data[object_type_cone] = object_flag_rt_only;
	data[object_type_cylinder] = object_flag_rt_only;
	data[object_type_box] = object_flag_universal;
	data[object_type_paraboloid] = object_flag_rt_only;
	data[object_type_limited]= object_flag_rt_only;
	data[object_type_moebius] = object_flag_rt_only;
	data[object_type_torus] = object_flag_rm_only;
	data[object_type_mandelbulb] = object_flag_rm_only;
	data[object_type_julia] = object_flag_rm_only;
	data[object_type_csg] = object_flag_rm_only;
	data[object_type_perforated_cube] = object_flag_rm_only;
}

t_object_flag				object_get_flag(t_object_type type)
{
	static t_object_flag	data[object_type_end];
	static int 				is_data_initialized;

	if (!is_data_initialized)
	{
		static_data_init(data);
		is_data_initialized = 1;
	}
	return (data[type]);
}