#ifndef RENDERER_H
# define RENDERER_H

# include "sdl_ctrl.h"
# include "camera.h"
# include "filter.h"
# include "scene.h"
# include "intersection.h"

typedef struct 		s_renderer
{
	t_sdl_ctrl		*sdl;
	t_camera		*camera;
	t_scene			*scene;
	t_intersection	intersection;
}					t_renderer;

t_renderer			*renderer_new();

void 				renderer_delete(t_renderer **renderer);

void				renderer_build_ray(t_renderer *renderer, INT_REF x, INT_REF y);

void 				renderer_run(t_renderer *renderer);

#endif
