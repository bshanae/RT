#include "renderer.h"

void				renderer_build_ray(t_renderer *renderer, INT_REF x, INT_REF y)
{
	renderer->intersection_shape.origin = renderer->camera->position;
	renderer->intersection_shape.direction = camera_build_ray(renderer->camera, x, y);
}