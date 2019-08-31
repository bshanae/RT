#include "texture.h"

void				texture_fill_data(
					t_texture *texture,
					unsigned char *stbi_data)
{
	RT_F4_API		*pointer;

	texture_get_space(texture);
	pointer = texture_iter(texture);
	texture_convert(texture, pointer, stbi_data);
	stbi_image_free(stbi_data);
}
