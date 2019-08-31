#include "texture.h"

t_texture			*texture_new(void)
{
	t_texture		*new;

	new = (t_texture *)malloc(sizeof(t_texture));
	new->textures_number = -1;
	new->data_size = 0;
	//texture_disruptions_load();
	texture_data_load(new, TEXTURE_CHESS);
//	texture_data_load(new, TEXTURE_WOOD);
//	texture_data_load(new, TEXTURE_PLANET);
	return (new);
}
