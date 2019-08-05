#ifndef RENDERER_H
# define RENDERER_H

# include "gui_image.h"
# include "scene.h"
# include "camera.h"
# include "ray.h"
# include "intersection.h"
# include "open_cl_manager.h"

typedef struct 			s_renderer
{
	t_scene				*scene;
	t_camera			*camera;
	t_gui_image			*image;
	t_color				*sample_store;
	t_open_cl_manager	*open_cl;
}						t_renderer;

t_renderer				*renderer_new(void);
void					renderer_delete(t_renderer **renderer);

t_vector3				renderer_frame(t_renderer *renderer);
t_color					renderer_pixel(t_renderer *renderer, t_ray *ray);

#endif
