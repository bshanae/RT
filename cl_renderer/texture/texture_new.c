#include "texture.h"

void				texture_initialization(t_texture *texture)
{
	texture->textures_number = -1;
	//texture_disruptions_load();
	texture_data_load(texture, TEXTURE_CHESS);
//	texture_data_load(texture, TEXTURE_WOOD);
//	texture_data_load(texture, TEXTURE_PLANET);
}
