#ifndef GUI_CAMERA_H
# define GUI_CAMERA_H

# include "rt_parameters.h"

# include "camera.h"

# include <gtk/gtk.h>

typedef struct		s_gui_camera
{
	GtkEntry		*position_x;
	GtkEntry		*position_y;
	GtkEntry		*position_z;
	GtkEntry		*rotation_x;
	GtkEntry		*rotation_y;
	GtkEntry		*rotation_z;
	GtkSwitch		*antialiasing;
	GtkSwitch		*focus;
	GtkEntry		*focal_length;
	GtkEntry		*aperture_size;
}					t_gui_camera;

t_gui_camera		*gui_camera_new(GtkBuilder *builder);
void 				gui_camera_delete(t_gui_camera **camera);

void 				gui_camera_show(t_gui_camera *gui, const t_camera *camera);

#endif
