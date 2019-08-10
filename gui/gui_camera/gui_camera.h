#ifndef GUI_CAMERA_H
# define GUI_CAMERA_H

# include <gtk/gtk.h>

typedef struct		s_gui_camera
{

}					t_gui_camera;

t_gui_camera		*gui_camera_new(GtkBuilder *builder);
void 				gui_camera_delete(t_gui_camera **camera);

#endif
