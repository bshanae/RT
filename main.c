#include "sdl_ctrl.h"

// Tutorial : https://lazyfoo.net/tutorials/SDL/index.php#Getting%20an%20Image%20on%20the%20Screen

int					main()
{
	t_sdl_ctrl		*sdl;
	int 			index;

	sdl = sdl_ctrl_new();
	sdl_init(sdl);

	index = 0;
	while (!sdl->flags.quit)
	{
		SDL_PollEvent(&sdl->event);
		if (sdl->event.type == SDL_QUIT)
			sdl->flags.quit = 1;
		else if (sdl->event.type == SDL_KEYDOWN)
		{
			if (sdl->event.key.keysym.sym == SDLK_LEFT)
				index--;
			else if (sdl->event.key.keysym.sym == SDLK_RIGHT)
				index++;
			else if (sdl->event.key.keysym.sym == SDLK_ESCAPE)
				sdl->flags.quit = 1;
			if (index > 1)
				index = 0;
			if (index == 0)
				sdl->surface_temp = SDL_LoadBMP("../land.bmp");
			else if (index == 1)
				sdl->surface_temp = SDL_LoadBMP("../land2.bmp");

			SDL_UpdateTexture(sdl->texture, NULL, sdl->frame, WINDOW_WIDTH * WINDOW_HEIGHT * sizeof(Uint32));

			SDL_RenderClear(sdl->renderer);
			SDL_RenderCopy(sdl->renderer, sdl->texture, NULL, NULL);
			SDL_RenderPresent(sdl->renderer);  
		}
	}

	sdl_ctrl_delete(&sdl);
	return (0);
}