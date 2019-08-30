#include "texture.h"

t_texture			*texture_new(void)
{
	t_texture		*new;

	new = (t_texture *)malloc(sizeof(t_texture));
	if (!(new->data = malloc(1)))
		exit (6);
	new->textures_number = -1;
//	texture_data_load(new, TEXTURE_CHESS);
	texture_data_load(new, TEXTURE_WOOD);
//	texture_data_load(new, TEXTURE_PLANET);
	return (new);
}
