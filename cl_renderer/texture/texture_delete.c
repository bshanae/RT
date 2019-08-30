#include "texture.h"

void 				texture_delete(t_texture **texture)
{
	free((*texture)->data);
	free(*texture);
	*texture = NULL;
}
