#include "sdl_ctrl.h"

void 				sdl_ctrl_delete(t_sdl_ctrl **sdl)
{
	SDL_DestroyTexture((*sdl)->texture);
	SDL_DestroyRenderer((*sdl)->renderer);
	SDL_DestroyWindow((*sdl)->window);
	SDL_Quit();
	free((*sdl)->data);
	free(*sdl);
	*sdl = NULL;
}