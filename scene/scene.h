#ifndef SCENE_H
# define SCENE_H

# include "parameters.h"

# include "shape.h"
# include "light.h"
# include "libft_vector.h"
# include "camera.h"

# define SCENE_DEF_BACKGROUND 	(t_vector3){.7, .7, .7}

typedef	struct					s_scene
{
	t_shape						shapes[SCENE_SHAPE_CAPACITY];
	int							shapes_length;
	t_light						lights[SCENE_LIGHT_CAPACITY];
	int							lights_length;
	t_vector3					background;
}								t_scene;

t_scene							*scene_new();

void							scene_delete(t_scene **scene);

void							scene_add_shape(t_scene *scene, t_shape shape);

void							scene_add_light(t_scene *scene, t_light light);

int 							scene_intersect(t_scene *scene, t_intersection *intersection);

void							scene_light_up(t_scene *scene, t_intersection *intersection);

#endif
