/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_disruptions_load.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 15:24:02 by ashari            #+#    #+#             */
/*   Updated: 2019/10/01 18:09:14 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "texture.h"

static RT_F4_API	disruption_mod(t_disruption_type type, double x, double y)
{
	if (type == checkerboard)
		return (disruption_checkerboard(x, y));
	else if (type == sine_wave)
		return (disruption_sine_wave(x, y));
	else if (type == perlin_noise)
		return (disruption_perlin_noise(x, y));
	return ((RT_F4_API){0., 0., 0., 0.});
}

static void			texture_compute_disruption(
					RT_F4_API *pointer, t_disruption_type type)
{
	int				x;
	int				y;

	x = 0;
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

void				texture_disruptions_load(
					t_texture *texture, t_disruption_type type, CHAR_REF name)
{
	RT_F4_API		*pointer;

	texture->textures_number++;
	pointer = texture_iter(texture);
	ft_strcpy(texture->name[texture->textures_number], name);
	texture->width[texture->textures_number] = DISRUPTION_WIDTH;
	texture->height[texture->textures_number] = DISRUPTION_HEIGHT - 1;
	texture->texture_length[texture->textures_number] =
		texture->width[texture->textures_number] *
		texture->height[texture->textures_number];
	texture_compute_disruption(pointer, type);
}
