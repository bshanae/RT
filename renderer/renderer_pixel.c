#include "renderer.h"

t_color				renderer_pixel(t_renderer *renderer, t_ray *ray)
{
	t_intersection	intersection;

	intersection.ray = *ray;
	intersection.ray.t = INFINITY;
	if (scene_intersect(renderer->scene, &intersection))
		return (t_color){255, 0, 0, 255};
	return ((t_color){0, 0, 0, 255});
}