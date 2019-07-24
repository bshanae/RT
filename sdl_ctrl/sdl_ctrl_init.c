#include "sdl_ctrl.h"

void				sdl_ctrl_init(t_sdl_ctrl *sdl)
{
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) < 0)
		sdl_ctrl_error(__FUNCTION__, __LINE__);

	SDL_GL_SetAttribute(SDL_GL_FRAMEBUFFER_SRGB_CAPABLE, 1); // todo this doesnt give effect

	sdl->window = SDL_CreateWindow
	(
		"oh hi Mark",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		WINDOW_WIDTH,
		WINDOW_HEIGHT,
		SDL_WINDOW_SHOWN
	);
	if (!sdl->window)
		sdl_ctrl_error(__FUNCTION__, __LINE__);
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
	sdl->data = (Uint32 *)malloc(sizeof(Uint32) * WINDOW_WIDTH * WINDOW_HEIGHT);
	ft_bzero(sdl->data, sizeof(Uint32) * WINDOW_WIDTH * WINDOW_HEIGHT);
}