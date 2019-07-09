#include "sdl_ctrl.h"

void				sdl_ctrl_init(t_sdl_ctrl *sdl)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
		sdl_ctrl_error(__FUNCTION__, __LINE__);
	sdl->window = SDL_CreateWindow
	(
		"SDL is strange",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		WINDOW_WIDTH,
		WINDOW_HEIGHT,
		SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE
	);
	if (!sdl->window)
		sdl_ctrl_error(__FUNCTION__, __LINE__);
	sdl->surface_main = SDL_GetWindowSurface(sdl->window);
	sdl->renderer = SDL_CreateRenderer
	(
		sdl->window,
		-1,
		SDL_RENDERER_ACCELERATED
	);
	sdl->texture = SDL_CreateTexture
	(
		sdl->renderer,
		SDL_PIXELFORMAT_ARGB8888,
		SDL_TEXTUREACCESS_STATIC,
		WINDOW_WIDTH,
		WINDOW_HEIGHT
	);
	sdl->frame = (Uint32 *)malloc(sizeof(Uint32) * WINDOW_WIDTH * WINDOW_HEIGHT);
}