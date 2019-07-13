#include "renderer.h"

void 				renderer_update_frame(t_renderer *renderer)
{
	printf("sample iteration %d\n", ++renderer->sample_number);
	for (int y = 0; y < WINDOW_HEIGHT; ++y)
		for (int x = 0; x < WINDOW_WIDTH; ++x)
		{
			renderer_build_ray(renderer, &x, &y);
			renderer_radiance(renderer);
			renderer_write_radiance(renderer, &x, &y);
		}
	if (renderer_check_interval(renderer))
		sdl_ctrl_upload(renderer->sdl);
}