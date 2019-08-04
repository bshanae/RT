#ifndef RENDERER_H
# define RENDERER_H

# include "scene.h"

typedef struct 		s_renderer
{
	t_scene			*scene;
}					t_renderer;

t_renderer			*renderer_new(void);

#endif
