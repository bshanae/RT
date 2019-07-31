#include "sdl_my.h"

#define TEXTURE_SIZE	1.931
#define WHITE			0xFFFFFF
#define BLACK			0

int 				checkerboard(int x, int y)
{
	double 			tmp;

	tmp = floor((double)x * TEXTURE_SIZE) + floor((double)y * TEXTURE_SIZE);
	if (fmod(tmp, 2.) == 0)
		return (WHITE);
	else
		return (BLACK);
}

#define PERLIN

void				update_frame(t_sdl *sdl)
{
	int 			x;
	int 			y;
	int 			result;

	x = 0;
	while (x < WINDOW_WIDTH)
	{
		y = 0;
		while (y < WINDOW_HEIGHT)
		{
#ifdef PERLIN
			result = noise(x, y);

#elif CHECKER
			result = checkerboard(x, y);
#endif
			sdl->data[x + y * WINDOW_WIDTH] = result;
			y++;
		}
		x++;
	}
	sdl_upload(sdl);
}

void				sdl_put_image_loop(t_sdl **sdl)
{
	while (!(*sdl)->flags.quit)
	{
		update_frame(*sdl);
		SDL_PollEvent(&(*sdl)->event);
		if ((*sdl)->event.type == SDL_QUIT)
				(*sdl)->flags.quit = 1;
		else if ((*sdl)->event.type == SDL_KEYDOWN)
		{
			if ((*sdl)->event.key.keysym.sym == SDLK_ESCAPE)
			{
				(*sdl)->flags.quit = 1;
				continue ;
			}
		}
	}
	sdl_delete(sdl);
}

