/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_initialization.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 15:24:15 by ashari            #+#    #+#             */
/*   Updated: 2019/09/29 15:24:16 by ashari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "texture.h"

void				texture_initialization(t_texture *texture)
{
	texture->textures_number = -1;
	texture_disruptions_load(texture, sine_wave, "Sine");
	texture_disruptions_load(texture, checkerboard, "Checkerboard");
//	texture_disruptions_load(texture, perlin_noise);
	texture_data_load(texture, RT_SOURCE_TEXTURE_CHESS, "Chess");
	texture_data_load(texture, RT_SOURCE_TEXTURE_WOOD, "Wood");
	texture_data_load(texture, RT_SOURCE_TEXTURE_PLANET, "Planet");
}
