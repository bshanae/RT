#ifndef SCENE_H
# define SCENE_H

# include "options.h"

# include "light.h"
# include "object_definition.h"

# include <stdlib.h>

# define SCENE_SPACE_OBJECT	0
# define SCENE_SPACE_LIGHT	1

typedef struct				s_scene
{
	t_object				objects[SCENE_OBJECTS_CAPACITY];
	int						objects_length;
	t_light					lights[SCENE_LIGHTS_CAPACITY];
	int						lights_length;
}							t_scene;

t_scene						*scene_new(void);
void						scene_delete(t_scene **scene);

void						*scene_get_space(t_scene *scene, int purpose);

#endif
