#include "texture.h"

void				texture_initialization(t_texture *texture)
{
	texture->textures_number = -1;
	texture_disruptions_load(texture, sine_wave);
	texture_disruptions_load(texture, checkerboard);
//	texture_disruptions_load(texture, perlin_noise);
	texture_data_load(texture, RT_SOURCE_TEXTURE_CHESS);
	texture_data_load(texture, RT_SOURCE_TEXTURE_WOOD);
	texture_data_load(texture, RT_SOURCE_TEXTURE_PLANET);
}
