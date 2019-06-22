#ifndef SCENE_H
# define SCENE_H

# include "shape.h"
# include "light.h"
# include "libft_vector.h"

typedef struct			s_scene_setting
{
	int 				diffuse_light;
	int 				specular_light;
	int 				shadows;
	int 				tshadows;
}						t_scene_setting;

typedef	struct			s_scene
{
	t_vector			shapes;
	t_vector			lights;
	t_vector3       	background;
	t_scene_setting		settings;
}						t_scene;

typedef	struct			s_scene_cl
{
	t_vector3       	background;
	t_scene_setting		settings;
	int 				shape_data_element_size;
	int 				shape_type_number;
	int 				shape_number;
	int 				light_number;
}						t_scene_cl;

t_scene             	*scene_new(t_vector3 background);

void					scene_delete(t_scene **me);

int 					scene_intersect
  (t_scene *me, t_intersection *intersection);

void					scene_light_up
   (t_scene *me, t_intersection *intersection);

void					scene_shape_push
  (t_scene *me, t_shape *shape);

t_shape					*scene_shape_at(t_scene *me, int i);

void					scene_light_push(t_scene *me, t_light *light);

t_light					*scene_light_at(t_scene *me, int i);

#endif
