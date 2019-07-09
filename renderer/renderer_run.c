#include "renderer.h"

void 				renderer_run(t_renderer *renderer)
{
	for (int sample = 0; sample < SAMPLES; sample++)
		for (int y = 0; y < WINDOW_HEIGHT; y++)
			for (int x = 0; x < WINDOW_WIDTH; x++)
			{
				renderer_build_ray(renderer, &x, &y);
			}
}