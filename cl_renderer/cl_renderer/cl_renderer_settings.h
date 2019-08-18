#ifndef CL_RENDERER_SETTINGS_H
# define CL_RENDERER_SETTINGS_H

typedef struct 				s_cl_renderer_settings
{
	int						sample_count;
	int						sample_limit;
	int 					sample_depth;
	int						russian_depth;
	int						srgb;
	int						light_pb;
	int 					light_explicit;
}							t_cl_renderer_settings;

#endif
