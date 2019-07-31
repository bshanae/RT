#include <sdl/sdl_my.h>
#include "preferences.h"
#include "disruptions.h"

int					main()
{
	t_sdl		*sdl;

	sdl = (t_sdl *)malloc(sizeof(t_sdl));
	sdl_init(sdl);
	sdl_put_image_loop(&sdl);
	return (0);
}