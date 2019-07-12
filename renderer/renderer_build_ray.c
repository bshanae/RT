#include "renderer.h"

void				renderer_build_ray(t_renderer *renderer, INT_REF x, INT_REF y)
{
	renderer->intersection_shape.ray = camera_build_ray(renderer->camera, x, y);
}
