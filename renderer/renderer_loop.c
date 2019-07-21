#include "renderer.h"

void				renderer_loop(t_renderer **renderer)
{
	t_sdl_ctrl		*sdl;

	sdl = (*renderer)->sdl;
	renderer_update_frame(*renderer);
	while (!sdl->flags.quit && (!QUIT_AFTER_SAMPLING || (*renderer)->sample_number < SAMPLES))
	{
		SDL_PollEvent(&sdl->event);
		if (sdl->event.type == SDL_QUIT)
			sdl->flags.quit = 1;
		else if (sdl->event.type == SDL_KEYDOWN)
		{
			if (sdl->event.key.keysym.sym == SDLK_ESCAPE)
			{
				sdl->flags.quit = 1;
				continue ;
			}
			else if (sdl->event.key.keysym.sym == SDLK_a)
				(*renderer)->camera->position.x -= CAMERA_STEP;
			else if (sdl->event.key.keysym.sym == SDLK_d)
				(*renderer)->camera->position.x += CAMERA_STEP;
			else if (sdl->event.key.keysym.sym == SDLK_w)
				(*renderer)->camera->position.z -= CAMERA_STEP;
			else if (sdl->event.key.keysym.sym == SDLK_s)
				(*renderer)->camera->position.z += CAMERA_STEP;
			else if (sdl->event.key.keysym.sym == SDLK_q)
				(*renderer)->camera->position.y += CAMERA_STEP;
			else if (sdl->event.key.keysym.sym == SDLK_e)
				(*renderer)->camera->position.z -= CAMERA_STEP;
			renderer_update_frame(*renderer);

		}
		else if ((*renderer)->sample_number < SAMPLES)
			renderer_update_frame(*renderer);
	}
	renderer_delete(renderer);
}