#include "sdl_my.h"

t_sdl 			*sdl_ctrl_new()
{
	t_sdl		*new;

	new = (t_sdl *)malloc(sizeof(t_sdl));
	new->window = NULL;
	new->renderer = NULL;
	new->flags.quit = 0;
	return (new);
}
