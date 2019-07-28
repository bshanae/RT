#ifndef RT_H
# define RT_H

# include "mlx.h"

# include "console.h"
# include "intersection.h"
# include "camera.h"
# include "scene.h"
# include "shape_list.h"
# include "mlx_keys.h"

# define WIN_WIDTH         1000
# define WIN_HEIGHT        500


# define CAMERA_POS_STEP	0.15
# define CAMERA_DIR_STEP	0.01
# define DEF_BACKGROUND 	(t_vector3){.0, .3, .3}

# define                    REFLECTION_DEPTH 2
# define                    REFRACTION_DEPTH 3

typedef	struct 				s_rt
{
	void					*mlx_ptr;
	void					*win_ptr;
	void					*img_ptr;
	int 					*img_data;
	t_camera				*camera;
	t_scene					*scene;
	struct
	{
		int 				is_on;
		u_long 				index;
	}						light_ctrl;
	struct
	{
		int 				is_on;
		u_long				index;
	}						object_ctrl;
	struct s_rt				*clone;
	t_console				*console;
	struct
	{
		int 				parallel;
		int 				reflection_depth;
		int 				refraction_depth;
		int 				*diffuse_light;
		int 				*specular_light;
		int 				*shadows;
		int 				*tshadows;
	}						settings;
}							t_rt;

t_rt						*rt_new();

void						rt_delete(t_rt **me);

void						rt_clone(t_rt *me);

void						rt_reset(t_rt **rt);

t_vector3					rt_ray_trace(t_rt *me, t_intersection *original, int reflection_depth, int refraction_depth);

void						rt_render(t_rt *me);

void						rt_build_open_cl(t_rt *me);

void						rt_consistent(t_rt *me);

void 						rt_parallel(t_rt *me);

void						rt_set_camera(t_rt *me, t_vector3 position);

void						rt_set_background(t_rt *me, t_vector3 color);

void						rt_perform(t_rt **me);

int							rt_key_press(int key, void *ptr);

int							rt_key_release(int key, void *ptr);

int							rt_exit(void *ptr);

#endif
