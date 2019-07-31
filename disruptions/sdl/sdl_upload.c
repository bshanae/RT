#include "sdl_my.h"

void				sdl_upload(t_sdl *sdl)
{
	SDL_UpdateTexture(sdl->texture, NULL, sdl->data, WINDOW_WIDTH * sizeof(Uint32));
	SDL_RenderCopy(sdl->renderer, sdl->texture, NULL, NULL);
	SDL_RenderPresent(sdl->renderer);
}
