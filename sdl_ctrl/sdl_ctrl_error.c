#include "sdl_ctrl.h"

void 				sdl_ctrl_error(const char *function, int line)
{
	ft_printf
	(
		"{red}SDL error : '%s'; Function : '%s', line '%d'\n",
		SDL_GetError(),
		function,
		line
	);
	exit(5);
}