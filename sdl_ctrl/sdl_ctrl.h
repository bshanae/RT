#ifndef SDL_CTRL_H
# define SDL_CTRL_H

# include "parameters.h"

# include "libft_ft_printf.h"

# include "SDL.h"

typedef struct 		s_sdl_flags
{
	int 			quit;
}					t_sdl_flags;

typedef struct 		s_sdl_ctrl
{
	SDL_Window		*window;
	SDL_Renderer	*renderer;
	SDL_Texture		*texture;
	Uint32 			*data;
	SDL_Event		event;
	t_sdl_flags		flags;
}					t_sdl_ctrl;

t_sdl_ctrl 			*sdl_ctrl_new();

void 				sdl_ctrl_delete(t_sdl_ctrl **sdl);

void 				sdl_ctrl_error(const char *function, int line);

void				sdl_ctrl_init(t_sdl_ctrl *sdl);

void				sdl_ctrl_upload(t_sdl_ctrl *sdl);

#endif
