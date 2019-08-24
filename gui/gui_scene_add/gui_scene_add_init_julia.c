#include "gui_scene_add.h"

void 							gui_scene_add_init_julia
								(t_gui_scene_add *edit, GtkBuilder *builder)
{
	t_gui_init_julia			init;

	ft_strcpy(init.iterations, "object_add_julia_iterations");
	ft_strcpy(init.value_x, "object_add_julia_value_x");
	ft_strcpy(init.value_y, "object_add_julia_value_y");
	ft_strcpy(init.value_z, "object_add_julia_value_z");
	ft_strcpy(init.value_w, "object_add_julia_value_w");
	edit->julia = gui_object_julia_init(&init, builder);
}
