#include "cl_renderer_settings.h"

void 				cl_renderer_settings_init(t_cl_renderer_settings *settings)
{
	settings->srgb = RT_CL_SRGB;
	settings->light_basic = RT_CL_LIGHT_BASIC;
	settings->light_area = RT_CL_LIGHT_AREA;
	settings->sample_count = 1;
	settings->sample_limit = RT_CL_SAMPLES;
	settings->sample_depth = RT_CL_DEPTH;
	settings->russian_mod = RT_CL_RUSSIAN_MOD;
	settings->russian_depth = RT_CL_RUSSIAN_DEPTH;
	settings->rm_mod = RT_CL_RM_MOD;
	settings->rm_step_limit = RT_CL_RM_STEP_LIMIT;
	settings->rm_step_part = RT_CL_STEP_PART;
	settings->rm_max_distance = RT_CL_RM_MAX_DISTANCE;
}