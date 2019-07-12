#include "renderer.h"

int 				renderer_check_upload(t_renderer *renderer)
{
	return (!((renderer->sample_number - 1) % UPLOAD_INTERVAL));
}