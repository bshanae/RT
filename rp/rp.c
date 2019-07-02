#include "rp.h"

t_rp				*rp_new(void)
{
	t_rp			*new;
	int 			temp[3];

	if (!(new = (t_rp *)malloc(sizeof(t_rp))))
		exit(21);
	new->mlx_ptr = mlx_init();
	new->win_ptr = mlx_new_window(new->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "RP");
	new->img_ptr = mlx_new_image(new->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	temp[0] = 8 * 4;
	temp[1] = WINDOW_WIDTH * 4;
	temp[2] = 0;
	new->img_data = (int *)mlx_get_data_addr(new->img_ptr, temp, temp + 1, temp + 2);
	new->camera = camera_new();
	new->scene = scene_new();
	return (new);
}

void 				rp_delete(t_rp **rp)
{
	camera_delete(&(*rp)->camera);
	scene_delete(&(*rp)->scene);
	free(*rp);
	*rp = NULL;
}
