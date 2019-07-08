#include "sdl_ctrl.h"

t_sdl_ctrl 			*sdl_ctrl_new()
{
	t_sdl_ctrl		*new;

	new = (t_sdl_ctrl *)malloc(sizeof(t_sdl_ctrl));
	new->window = NULL;
	new->surface_main = NULL;
	new->surface_temp = NULL;
	new->renderer = NULL;
	new->frame = NULL;
	new->flags.quit = 0;
	return (new);
}