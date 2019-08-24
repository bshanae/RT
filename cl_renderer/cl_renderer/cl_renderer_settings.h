#ifndef CL_RENDERER_SETTINGS_H
# define CL_RENDERER_SETTINGS_H

# include "rt_cl_include.h"
# include "rt_float.h"
# include "rt_parameters.h"

typedef struct 		s_cl_renderer_settings
{
	int				srgb;
	int 			light_basic;
	int 			light_area;
	int 			sample_count;
	int 			sample_limit;
	int 			sample_depth;
	int 			russian_mod;
	int				russian_depth;
	int 			rm_mod;
	int 			rm_step_limit;
	RT_F			rm_step_part;
	int 			rm_max_distance;
	int				cartoon_effect; // todo: for this we need Phong lightning
	int				filter_sepia;
	int 			filter_stereoscopy;
}					t_cl_renderer_settings;

void 				cl_renderer_settings_init(t_cl_renderer_settings *settings);

#endif
