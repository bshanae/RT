#include "gui_scene_add.h"

t_gui_scene_add		*gui_scene_add_new(GtkBuilder *builder)
{
	t_gui_scene_add	*new;

	printf("GUI : Initializing object creator\n");
	new = rt_malloc(sizeof(t_gui_scene_add));
	new->current_type = object_type_end;
	new->gen_name_next = 0;
	new->material_color_silent = 0;
	gui_scene_add_init_own(new, builder);
	gui_scene_add_init_light_point(new, builder);
	gui_scene_add_init_light_direct(new, builder);
	gui_scene_add_init_sphere(new, builder);
	gui_scene_add_init_plane(new, builder);
	gui_scene_add_init_cone(new, builder);
	gui_scene_add_init_cylinder(new, builder);
	gui_scene_add_init_box(new, builder);
	gui_scene_add_init_paraboloid(new, builder);
	gui_scene_add_init_moebius(new, builder);
	gui_scene_add_init_torus(new, builder);
	gui_scene_add_init_mandelbulb(new, builder);
	gui_scene_add_init_julia(new, builder);
	gui_scene_add_init_material(new, builder);
	gui_scene_add_load_types(new);
	return (new);
}