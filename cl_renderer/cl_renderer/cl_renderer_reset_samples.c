#include "cl_renderer.h"

void 				cl_renderer_reset_samples(t_cl_renderer *renderer)
{
	renderer->flags.update_settings = 1;
	renderer->data_host.settings.sample_count = 0;
}