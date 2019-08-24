#include "gui_scene_add.h"

void 							gui_scene_add_init_mandelbulb
								(t_gui_scene_add *edit, GtkBuilder *builder)
{
	t_gui_init_mandelbulb		init;

	ft_strcpy(init.iterations, "object_add_mandelbulb_iterations");
	ft_strcpy(init.power, "object_add_mandelbulb_power");
	edit->mandelbulb = gui_object_mandelbulb_init(&init, builder);

}