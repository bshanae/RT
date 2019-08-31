#include "texture.h"

void				texture_disruption_mod(t_texture *texture, RT_F4_API *pointer, t_disruption_type type)
{
	if (type == checkerboard)
		;//checkerboard_disruption(pointer);
	else if (type == sine_wave)
		;//sine_wave_disruption(pointer);
	else if (type == perlin_noise)
		;//perlin_noise_disruption(pointer);
}

void				texture_disruptions_load(t_texture *texture, t_disruption_type type)
{
	RT_F4_API		*pointer;

	pointer = texture_iter(texture);
	texture_disruption_mod(texture, pointer, type);
}