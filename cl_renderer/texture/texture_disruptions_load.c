#include "texture.h"

static RT_F4_API	disruption_mod(t_disruption_type type, double x, double y)
{
	if (type == checkerboard)
		return (disruption_checkerboard(x, y));
	else if (type == sine_wave)
		return (disruption_sine_wave(x, y));
	else if (type == perlin_noise)
		return (disruption_perlin_noise(x, y));
}

void				texture_compute_disruption(t_texture *texture, RT_F4_API *pointer, t_disruption_type type)
{
	int 			x;
	int 			y;

	x  = 0;
	while (x < DISRUPTION_WIDTH)
	{
		y = 0;
		while (y < DISRUPTION_HEIGHT)
		{
			*pointer = disruption_mod(type, (double)x, (double)y);
			pointer++;
			y++;
		}
		x++;
	}
}

void				texture_disruptions_load(t_texture *texture, t_disruption_type type)
{
	RT_F4_API		*pointer;

	texture->textures_number++;
	pointer = texture_iter(texture);
	texture->width[texture->textures_number] = DISRUPTION_WIDTH;
	texture->height[texture->textures_number] = DISRUPTION_HEIGHT;
	texture->texture_length[texture->textures_number] = texture->width[texture->textures_number]
														* texture->height[texture->textures_number];
	texture_compute_disruption(texture, pointer, type);
}