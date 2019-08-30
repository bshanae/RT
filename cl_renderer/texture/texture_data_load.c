#include "texture.h"

# define STB_IMAGE_IMPLEMENTATION
# include "stb_image.h"

#define CHANNELS 4

static void				convert_to_float(const t_texture *texture,
									 RT_F4_API *pointer,
									 const unsigned char *stbi_data)
{
	int 			pixel_index;
	int 			size;

	pixel_index = 0;
	size = texture->texture_length[texture->textures_number] * CHANNELS;
	while (pixel_index < size)
	{
		pointer->x = (RT_F)stbi_data[pixel_index] / 255;
		pointer->y = (RT_F)stbi_data[pixel_index + 1] / 255;
		pointer->z = (RT_F)stbi_data[pixel_index + 2] / 255;
		pointer->w = 1.;
		pointer++;
		pixel_index += CHANNELS;
	}
}

static void			fill_texture_data(t_texture *texture, unsigned char	*stbi_data)
{

	int 			i;
	RT_F4_API		*pointer;

	i = 0;
	pointer = &texture->data[0];
	while (i < texture->textures_number)
		pointer += texture->texture_length[i++];
	convert_to_float(texture, pointer, stbi_data);

	stbi_image_free(stbi_data);
}

void				texture_data_load(t_texture *texture, const char *path)
{
	unsigned char	*stbi_data;
	int 			texture_width;
	int 			texture_height;
	int 			number_of_channels;

	stbi_set_flip_vertically_on_load(0);
	if (!stbi_info(path, &texture_width, &texture_height, &number_of_channels))
	{
		printf("Can't open texture file\n");
		exit (9);
	}

	stbi_data = stbi_load(path, &texture_width, &texture_height, &number_of_channels, CHANNELS);
	texture->textures_number++;
	texture->texture_length[texture->textures_number] = texture_width * texture_height;
	if (texture->texture_length[texture->textures_number] >= MAX_TEXTURE_SIZE)
	{
		stbi_image_free(stbi_data);
		printf("Texture size : %d is more than MAX_TEXTURE_SIZE : %d\n",
			   texture->texture_length[texture->textures_number], MAX_TEXTURE_SIZE);
		exit(9);
	}
	else if (texture->textures_number >= MAX_TEXTURES_NUMBER)
	{
		stbi_image_free(stbi_data);
		printf("Too much textures\n");
		exit(9);
	}
	fill_texture_data(texture, stbi_data);
}
