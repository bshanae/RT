#include "renderer.h"

void				renderer_write_radiance(t_renderer *renderer, INT_REF x, INT_REF y)
{
	renderer->sample_data[*y * WINDOW_WIDTH + *x] = renderer->radiance;
	renderer->sdl->data[*y * WINDOW_WIDTH + *x] = color_unpack(renderer->sample_data[*y * WINDOW_WIDTH + *x]);
	return ;

	if (renderer->sample_number == 1)
		renderer->sample_data[*y * WINDOW_WIDTH + *x] = renderer->radiance;
	else
		vector3_add_eq_ref(renderer->sample_data + *y * WINDOW_WIDTH + *x, &renderer->radiance);
	if (renderer_check_interval(renderer))
		renderer->sdl->data[*y * WINDOW_WIDTH + *x] = color_unpack(vector3_mul_ref(renderer->sample_data + *y * WINDOW_WIDTH + *x, 1. / renderer->sample_number));
}