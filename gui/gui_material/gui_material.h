#ifndef GUI_MATERIAL_H
# define GUI_MATERIAL_H

# include "rt_parameters.h"

# include "gui_entry.h"
# include "gui_color.h"
# include "material.h"

# include <gtk/gtk.h>

typedef struct 		s_gui_init_material
{
	char 			color_r[64];
	char 			color_g[64];
	char 			color_b[64];
	char			color_button[64];
	char			emission_r[64];
	char			emission_g[64];
	char			emission_b[64];
	char			emission_button[64];
}					t_gui_init_material;

typedef struct 		s_gui_material
{
	GtkEntry		*color_r;
	GtkEntry		*color_g;
	GtkEntry		*color_b;
	GtkColorButton	*color_button;
	GtkEntry		*emission_r;
	GtkEntry		*emission_g;
	GtkEntry		*emission_b;
	GtkColorButton	*emission_button;
}					t_gui_material;

t_gui_material		gui_material_init
					(const t_gui_init_material *init, GtkBuilder *builder);

void 				gui_material_get
					(t_gui_material *gui, t_material *material);
void 				gui_material_set
					(t_gui_material *gui, t_material *material);

#endif
