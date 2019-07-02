#ifndef RP_H
# define RP_H

# include "color_list.h"
# include "parameters.h"
# include "mlx_keys.h"

# include "color.h"
# include "camera.h"
# include "intersection.h"
# include "scene.h"

# include "mlx.h"
# include "time.h"
# include "stdio.h"

typedef struct		s_rp
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	int 			*img_data;
	t_camera		*camera;
	t_scene			*scene;
}					t_rp;

t_rp				*rp_new(void);

void 				rp_delete(t_rp **rp);

t_vector3			rp_cast_ray(t_rp *rp, t_intersection me, int depth);

void 				rp_render(t_rp *rp);

int					rp_key_press(int key, t_rp *rp);

int					rp_exit(t_rp *rp);

#endif
