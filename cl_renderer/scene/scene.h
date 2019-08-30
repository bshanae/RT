#ifndef SCENE_H
# define SCENE_H

# include "rt_parameters.h"

# include "object_interaction.h"
# include "texture.h"

# include <stdlib.h>

typedef struct		s_scene
{
	t_object		objects[RT_CL_SCENE_CAPACITY];
	int				objects_length;
	int				lights[RT_CL_SCENE_CAPACITY];
	int 			lights_length;
	t_texture		*textures[MAX_TEXTURES_NUMBER];
}					t_scene;

t_scene				*scene_new(void);
void				scene_delete(t_scene **scene);

void 				scene_clear(t_scene *scene);
void 				scene_update(t_scene *scene);
t_object			*scene_get_space(t_scene *scene);
void 				scene_remove_object(t_scene *scene, int object_id);

#endif
