#ifndef GUI_COLOR_H
# define GUI_COLOR_H

# include "rt_cl_include.h"
# include "rt_float.h"

# include <gtk/gtk.h>

typedef GdkRGBA		t_gui_color;

RT_F4_API			gui_color_to_f4(const t_gui_color *source);
t_gui_color			gui_color_from_f4(const RT_F4_API *source);

#endif