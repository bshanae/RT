#ifndef SCENE_H
# define SCENE_H

# include "rt_parameters.h"
# include "scene_point.h"

# include "object_interaction.h"

# include <stdlib.h>

typedef struct		s_scene
{
	t_object		objects[RT_CL_SCENE_CAPACITY];
	int				objects_length;
	int				lights[RT_CL_SCENE_CAPACITY];
	int 			lights_length;
}					t_scene;

t_scene				*scene_new(void);
void				scene_delete(t_scene **scene);

void 				scene_clear(t_scene *scene);
void 				scene_update(t_scene *scene);
t_object			*scene_get_space(t_scene *scene);
void 				scene_remove_object(t_scene *scene, int object_id);
int 				scene_point_check(t_scene *scene, const RT_F4_API *point);
void				scene_select(t_scene *scene, int id);

typedef enum		e_scene_name_flag
{
	scene_name_next,
	scene_name_last,
	scene_name_id,
	scene_name_reset
}					t_scene_name_flag;

void				scene_give_name
					(t_scene *scene, CHAR_REF str, t_scene_name_flag flag, ...);

int					scene_is_valid_id(t_scene *scene, int id);
int					scene_is_valid_content(t_scene *scene);

#endif
