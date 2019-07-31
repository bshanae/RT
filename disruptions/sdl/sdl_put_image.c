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

#define TAU 6.2831853071

void				recalculate_values(double *x, double *y)
{
	*x = *x / WINDOW_WIDTH + sin(TAU);
	*y = *y / WINDOW_HEIGHT + cos(TAU);
}

int 				sinewave_texture(double x, double y)
{
	t_color			color;

	recalculate_values(&x, &y);
	x *= (double)WINDOW_WIDTH / WINDOW_HEIGHT;
	x += sin(y * 3.) / 10.;
	y += sin(x * 4.) / 5.;
	if (fmod(y + y, .2) <= 0.1)
	{
		color.rgb.a = 0;
		color.rgb.r = 0;
		color.rgb.g = 191;
		color.rgb.b = 255;
	}
	else
	{
		color.rgb.a = 0;
		color.rgb.r = 224;
		color.rgb.g = 255;
		color.rgb.b = 255;
	}
	return (color.mix);
}

#define WAVES

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
#ifdef WAVES
			result = sinewave_texture(x, y);
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

