# define STB_IMAGE_IMPLEMENTATION

#include "texture.h"

void				texture_data_load(t_texture *texture, const char *path)
{
	unsigned char	*stbi_data;
	int 			number_of_channels;

	stbi_set_flip_vertically_on_load(0);
	texture->textures_number++;
	if (!stbi_info(path, &texture->width[texture->textures_number],
			&texture->height[texture->textures_number],
			&number_of_channels))
	{
		printf("Can't open texture file\n");
		exit (9);
	}
	stbi_data = stbi_load(path, &texture->width[texture->textures_number],
			&texture->height[texture->textures_number],
			&number_of_channels, TEXTURE_CHANNELS);
	(texture->width[texture->textures_number])--;
	(texture->height[texture->textures_number])--;
	texture->texture_length[texture->textures_number] = texture->width[texture->textures_number]
		* texture->height[texture->textures_number];
	texture_fill_data(texture, stbi_data);
}
