#include "gui_scene_edit.h"

void 							gui_scene_edit_init_mandelbulb
								(t_gui_scene_edit *edit, GtkBuilder *builder)
{
	t_gui_init_mandelbulb		init;

	ft_strcpy(init.iterations, "object_edit_mandelbulb_iterations");
	ft_strcpy(init.power, "object_edit_mandelbulb_power");
	edit->mandelbulb = gui_object_mandelbulb_init(&init, builder);

}