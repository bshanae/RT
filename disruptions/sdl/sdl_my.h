#ifndef DISRUPTIONS_SDL_MY_H
#define DISRUPTIONS_SDL_MY_H

# include <SDL.h>

# include "preferences.h"
# include "perlin_noise/perlin_noise.h"

typedef struct 		s_sdl_flags
{
	int 			quit;
}					t_sdl_flags;

typedef struct 		s_sdl
{
	SDL_Window		*window;
	SDL_Renderer	*renderer;
	SDL_Texture		*texture;
	Uint32 			*data;
	SDL_Event		event;
	t_sdl_flags		flags;
}					t_sdl;

void 				sdl_delete(t_sdl **sdl);

void 				sdl_error(const char *function, int line);

void				sdl_init(t_sdl *sdl);

void				sdl_upload(t_sdl *sdl);

void				sdl_put_image_loop(t_sdl **sdl);


#endif //DISRUPTIONS_SDL_MY_H
