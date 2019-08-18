#ifndef GUI_MATERIAL_H
# define GUI_MATERIAL_H

# include "rt_parameters.h"

# include "material.h"
# include "gui_color.h"

# include <gtk/gtk.h>

typedef struct 		s_gui_init_material
{
	char			color[64];
	char			emission[64];
}					t_gui_init_material;

typedef struct 		s_gui_material
{
	GtkColorButton	*color;
	GtkColorButton	*emission;
}					t_gui_material;

t_gui_material		gui_material_set
					(const t_gui_init_material *init, GtkBuilder *builder);

void 				gui_material_show
					(t_gui_material *gui, t_material *material);
void 				gui_material_build
					(t_gui_material *gui, t_material *material);

#endif
