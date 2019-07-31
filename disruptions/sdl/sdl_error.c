#include "sdl_my.h"

void 				sdl_error(const char *function, int line)
{
	printf
			(
				"{red}SDL error : '%s'; Function : '%s', line '%d'\n",
				SDL_GetError(),
				function,
				line
			);
	exit(5);
}
