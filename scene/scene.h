#ifndef SCENE_H
# define SCENE_H

# include "shape.h"
# include "light.h"

typedef struct 		s_scene
{
	t_shape			shapes[SCENE_SHAPES_CAPACITY];
	int 			shapes_length;
	t_light			lights[SCENE_LIGHTS_CAPACITY];
	int 			lights_length;
}					t_scene;

#endif
