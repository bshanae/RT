#ifndef RENDERER_H
# define RENDERER_H

# include "sdl_ctrl.h"
# include "color.h"
# include "color_list.h"
# include "camera.h"
# include "filter.h"
# include "shape_list.h"
# include "scene.h"
# include "intersection.h"

typedef struct 		s_renderer
{
	t_sdl_ctrl		*sdl;
	t_camera		*camera;
	t_scene			*scene;
	t_intersection	intersection_shape;
	t_intersection	intersection_light;
	t_vector3		radiance;
	int				depth;
	t_vector3		*sample_data;
	int				sample_number;
}					t_renderer;

t_renderer			*renderer_new();

void 				renderer_delete(t_renderer **renderer);

void				renderer_build_ray(t_renderer *renderer, INT_REF x, INT_REF y);

void 				renderer_update_frame(t_renderer *renderer);

void				renderer_loop(t_renderer **renderer);

void				renderer_get_radiance(t_renderer *renderer);

void				renderer_write_radiance(t_renderer *renderer, INT_REF x, INT_REF y);


#endif
