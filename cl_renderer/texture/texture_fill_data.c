#include "texture.h"

void				texture_fill_data(
					t_texture *texture,
					unsigned char *stbi_data)
{
	int 			i;
	RT_F4_API		*pointer;

	i = 0;
	texture_get_space(texture);
	pointer = &texture->data[0];
	while (i < texture->textures_number)
		pointer += texture->texture_length[i++];
	texture_convert(texture, pointer, stbi_data);
	stbi_image_free(stbi_data);
}
