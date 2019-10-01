/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 15:23:37 by ashari            #+#    #+#             */
/*   Updated: 2019/10/01 18:09:14 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURE_H
# define TEXTURE_H

# include "rt_parameters.h"
# include "rt_cl_include.h"
# include "rt_float.h"
# include "rt_sources_texture.h"

# include "libft_standart.h"
# include "error_framework.h"
# include "disruption.h"

# include <stdlib.h>
# include <stb_image.h>

# define TEXTURE_CHANNELS		4

typedef struct				s_texture
{
	char					name[RT_TEXTURE_MAX_NUMBER][RT_NAME_SIZE];
	RT_F4_API				data[RT_TEXTURE_DATA_SIZE];
	int						texture_length[RT_TEXTURE_MAX_NUMBER];
	int						width[RT_TEXTURE_MAX_NUMBER];
	int						height[RT_TEXTURE_MAX_NUMBER];
	int						textures_number;
}							t_texture;

void						texture_initialization(t_texture *texture);

void						texture_data_load
							(t_texture *texture,
							const char *path, CHAR_REF name);
void						texture_disruptions_load
							(t_texture *texture,
							t_disruption_type type, CHAR_REF name);

void						texture_fill_data(
							t_texture *texture,
							unsigned char *stbi_data);

RT_F4_API					*texture_iter(t_texture *texture);

void						texture_convert(
							const t_texture *texture,
							RT_F4_API *pointer,
							const unsigned char *stbi_data);

#endif
