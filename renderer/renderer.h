#ifndef RENDERER_H
# define RENDERER_H

# include "gui_image.h"
# include "scene.h"

typedef struct 		s_renderer
{
	t_scene			*scene;
	t_gui_image		*image;
}					t_renderer;

t_renderer			*renderer_new(void);

#endif
