#ifndef CL_RENDERER_SETTINGS_H
# define CL_RENDERER_SETTINGS_H

# include "rt_cl_include.h"
# include "rt_float.h"
# include "rt_parameters.h"

typedef struct 		s_cl_renderer_settings
{
	int 			light_basic;
	int 			light_area;
	int 			illumination;
	RT_F 			illumination_value;
	int 			sample_count;
	int 			sample_limit;
	int 			sample_depth;
	int 			rm_mod;
	int 			rm_step_limit;
	RT_F			rm_step_part;
	int 			rm_max_distance;
}					t_cl_renderer_settings;

void 				cl_renderer_settings_init(t_cl_renderer_settings *settings);

#endif
