#include "sdl_ctrl.h"

void				sdl_ctrl_upload(t_sdl_ctrl *sdl)
{
	SDL_UpdateTexture(sdl->texture, NULL, sdl->data, WINDOW_WIDTH * sizeof(Uint32));
	SDL_RenderCopy(sdl->renderer, sdl->texture, NULL, NULL);
	SDL_RenderPresent(sdl->renderer);
}