#include "renderer.h"

t_vector3			renderer_frame(t_renderer *renderer)
{
	t_ray			ray;

	for (int y = 0; y < renderer->image->width; y++)
		for (int x = 0; x < renderer->image->width; x++)
		{
			ray = camera_build_ray(renderer->camera, &x, &y);
			renderer->image->color_buffer[renderer->image->width * y + x] =
				renderer_pixel(renderer, &ray);
		}
}
