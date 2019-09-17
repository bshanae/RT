#ifndef CL_RENDERER_SETTINGS_H
# define CL_RENDERER_SETTINGS_H

# include "rt_cl_include.h"
# include "rt_float.h"
# include "rt_parameters.h"

# include "libft_standart.h"

# include "object_flag.h"

typedef struct 			s_cl_renderer_settings
{
	int 				light_basic;
	int 				light_area;
	int 				illumination;
	RT_F 				illumination_value;
	int 				sample_count;
	int 				sample_limit;
	int 				sample_depth;
	int					motion_blur;
	int					motion_blur_sample_count;
	t_rt_tracing_mod	tracing_mod;
	UINT 				tracing_mod_mask;
	int 				rm_step_limit;
	RT_F				rm_step_part;
	RT_F				rm_max_distance;
}						t_cl_renderer_settings;

void 				cl_renderer_settings_init(t_cl_renderer_settings *settings);

#endif
