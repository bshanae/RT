#include "renderer.h"

int 				renderer_check_interval(t_renderer *renderer)
{
	return (!((renderer->sample_number - 1) % UPLOAD_INTERVAL));
}