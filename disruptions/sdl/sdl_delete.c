#include "sdl_my.h"

void 				sdl_delete(t_sdl **sdl)
{
	SDL_DestroyTexture((*sdl)->texture);
	SDL_DestroyRenderer((*sdl)->renderer);
	SDL_DestroyWindow((*sdl)->window);
	SDL_Quit();
	free((*sdl)->data);
	free(*sdl);
	*sdl = NULL;
}
