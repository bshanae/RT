#ifndef SCENE_H
# define SCENE_H

# include "light.h"
# include "shape.h"
# include "mesh.h"

typedef struct 		s_scene
{
	t_shape			shapes[SCENE_SHAPES_CAPACITY];
	int 			shapes_length;
	t_mesh			*mesh;
	t_light			lights[SCENE_LIGHTS_CAPACITY];
	int 			lights_length;
}					t_scene;

t_scene				*scene_new();

void				scene_delete(t_scene **scene);

void				scene_add_shape(t_scene *scene, t_shape shape);

void				scene_add_light(t_scene *scene, t_light light);

int					scene_intersect(t_scene *scene, t_intersection *intersection);

#endif
