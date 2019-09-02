#ifndef TEXTURE_H
# define TEXTURE_H

# include <stdlib.h>
# include <OpenCL/opencl.h>

# include "rt_parameters.h"
# include "rt_float.h"
# include "rt_sources_texture.h"

# include "libft_standart.h"
# include "disruption.h"

# include <stb_image.h>

# define TEXTURE_CHANNELS		4

typedef struct 				s_texture
{
	RT_F4_API				data[TEXTURE_DATA_SIZE];
	int 					texture_length[TEXTURE_MAX_NUMBER];
	int						width[TEXTURE_MAX_NUMBER];
	int						height[TEXTURE_MAX_NUMBER];
	int 					textures_number;
}							t_texture;

void						texture_initialization(t_texture *texture);

void						texture_data_load(t_texture *texture, const char *path);

void						texture_disruptions_load(t_texture *texture, t_disruption_type type);

void						texture_fill_data(
							t_texture *texture,
							unsigned char *stbi_data);

RT_F4_API					*texture_iter(t_texture *texture);

void						texture_convert(
							const t_texture *texture,
							RT_F4_API *pointer,
							const unsigned char *stbi_data);

#endif
