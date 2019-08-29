#include "gui_scene_edit.h"

t_gui_scene_edit		*gui_scene_edit_new(GtkBuilder *builder)
{
	t_gui_scene_edit	*new;

	printf("Initializing object editor\n");
	new = malloc(sizeof(t_gui_scene_edit));
	gui_scene_edit_init_own(new, builder);
	gui_scene_edit_init_light_point(new, builder);
	gui_scene_edit_init_light_direct(new, builder);
	gui_scene_edit_init_sphere(new, builder);
	gui_scene_edit_init_plane(new, builder);
	gui_scene_edit_init_cone(new, builder);
	gui_scene_edit_init_cylinder(new, builder);
	gui_scene_edit_init_box(new, builder);
	gui_scene_edit_init_paraboloid(new, builder);
	gui_scene_edit_init_moebius(new, builder);
	gui_scene_edit_init_torus(new, builder);
	gui_scene_edit_init_mandelbulb(new, builder);
	gui_scene_edit_init_julia(new, builder);
	gui_scene_edit_init_material(new, builder);
	new->current_id = -1;
	return (new);
}