#include "texture.h"

void				texture_initialization(t_texture *texture)
{
	texture->textures_number = -1;
	texture_data_load(texture, TEXTURE_PLANET);
	texture_data_load(texture, TEXTURE_TEST);
	texture_disruptions_load(texture, sine_wave);
	texture_disruptions_load(texture, checkerboard);
//	texture_disruptions_load(texture, perlin_noise);
	texture_data_load(texture, TEXTURE_CHESS);
	texture_data_load(texture, TEXTURE_WOOD);
}
