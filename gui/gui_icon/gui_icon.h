#ifndef GUI_ICON_H
# define GUI_ICON_H

# include "rt_parameters.h"
# include "rt_sources_gui.h"

# include "libft_standart.h"

# include <gtk/gtk.h>

typedef struct 		s_pair_i
{
	int 			first;
	int				second;
}					t_pair_i;

void 				gui_icon_load
					(GtkBuilder *builder, CHAR_REF image_name,
					CHAR_REF path_to_file, t_pair_i size);
void 				gui_icon_load_all(GtkBuilder *builder);

#endif
